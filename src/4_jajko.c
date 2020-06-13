#include"4_jajko.h"
#include"gluchytelefon.h"

int main(){
    logger(INFO, "4. Jajko (lustrzane odbicie bitów)");

    long int number = receive();

    printf("[INPUT] %ld\n", number);

    return 0;
}

long int receive(){
    int fd;
    char buffer[BUFFER_SIZE];

    fd = open(CHRDEV_PATH, O_RDONLY);
    if (fd < 0){
        perror("Failed to open CHRDEV");
        exit(0);
    }
    read(fd, buffer, BUFFER_SIZE);

    close(fd);

    return atol(buffer);
}