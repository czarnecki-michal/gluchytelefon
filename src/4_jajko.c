#include"4_jajko.h"
#include"gluchytelefon.h"

int main(){
    logger(INFO, "4. Jajko (lustrzane odbicie bitów)");

    long int number = receive();

    printf("[INPUT] %ld\n", number);

    number = reverse_bits(number);

    printf("[OUTPUT] %ld\n", number);

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

unsigned int reverse_bits(unsigned int num) 
{ 
    unsigned int NO_OF_BITS = sizeof(num) * 8; 
    unsigned int reverse_num = 0, i, temp; 
  
    for (i = 0; i < NO_OF_BITS; i++) 
    { 
        temp = (num & (1 << i)); 
        if(temp) 
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i)); 
    } 
   
    return reverse_num; 
} 
