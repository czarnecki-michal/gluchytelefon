#include "3_pipe.h"
#include "gluchytelefon.h"

int main(){
    logger(INFO, "3. Pipe (x:= ustawienie bitu na pozycji określonej przez x)");

    char buffer[BUFFER_SIZE];
    long int number = receive();

    sprintf(buffer, "%ld", number);
    logger(INPUT, buffer);
    
    number = transform(number);
    if(!checkRange(number)){
        logger(ERROR, "OUT OF RANGE");
    }

    sprintf(buffer, "%ld", number);
    logger(OUTPUT, buffer);

    // send(number);

    return 0;
}

long int receive(){
    int fd;
    char buffer[sizeof(int) * 8];

    fd = open(FIFO_PATH, O_RDONLY);

    if(read(fd, buffer, sizeof(int) * 8) < 0){
        logger(ERROR, "Couldn't read from fifo");
        exit(0);
    }

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