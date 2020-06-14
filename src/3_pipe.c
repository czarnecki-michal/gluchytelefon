#include "3_pipe.h"
#include "gluchytelefon.h"

int main(){
    logger(INFO, "3. Pipe (x:= ustawienie bitu na pozycji określonej przez x)");

    long int number = receive();

    printf("[INPUT] %ld\n", number);

    number = transform(number);
    if(!checkRange(number)){
        logger(ERROR, "OUT OF RANGE");
    }

    printf("[OUTPUT] %ld\n", number);

    send(number);

    return 0;
}

long int receive(){
    int fd;
    char buffer[BUFFER_SIZE];

    fd = open(FIFO_PATH, O_RDONLY);

    read(fd, buffer, BUFFER_SIZE);

    close(fd);
    unlink(FIFO_PATH);

    return atol(buffer);
}

long int set_bit(unsigned int data, unsigned int position){
    return (data | (1 << position));
}

long int transform(long int value){
    unsigned int c_data = 0x00;
    
    c_data = set_bit(c_data, value);

    return c_data;
}

void send(const unsigned int value){
    int fd; 

    char * txt = NULL;
    asprintf(&txt, "%u", value);
    fd = open(CHRDEV_PATH, O_WRONLY);
    if(fd < 0){
        perror("Failder to open CHRDEV");
        exit(0);
    }

    write(fd, txt, BUFFER_SIZE);

    close(fd);
    free(txt);

    execl("./4_jajko.out", "software", NULL);
}