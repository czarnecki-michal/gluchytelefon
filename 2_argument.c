#include"gluchytelefon.h"
#include"2_argument.h"

int main(int argc, char * argv[]){
    logger(INFO, "2. Argument (x:=nastepna liczba pierwsza)");
    char buffer[BUFFER_SIZE];

    long number = parse_args(argc, argv);

    sprintf(buffer, "%ld", number); 
    logger(INPUT, buffer);

    long next_prime = find_prime(number);

    if(!checkRange(next_prime)){
        logger(ERROR, "OUT OF RANGE");
    }

    sprintf(buffer, "%ld", next_prime);
    logger(OUTPUT, buffer);

    return 0;
}

long int parse_args(int argc, char * argv[]){
    int param;
    long int number = 0;

    while((param = getopt(argc, argv, "i:")) != -1){
        if (param == 'i'){
            number = atol(optarg);
            return number;
        }
    }
    return -1;
}

bool is_prime(int num)
{
     if (num <= 1) return 0;
     if (num % 2 == 0 && num > 2) return 0;
     for(int i = 3; i < num / 2; i+= 2)
     {
         if (num % i == 0)
             return false;
     }
     return true;
}

long int find_prime(long int value){
    int prime = value + 1;
    int found = 0;

    while(!found){
        prime++;
        if(is_prime(prime)){
            found = 1;
        }
    }

    return prime;
}

void send(const unsigned int value){
    int fd;
    char * txt = NULL;

	mkfifo(FIFO_PATH, 0666);

	fd = open(FIFO_PATH, O_WRONLY);
    asprintf(&txt, "%u", value);

    if(write(fd, txt, sizeof(int) * 8) < 0){
        logger(ERROR, "Couldn't write to fifo");
        exit(0);
    }else{
	    close(fd);
        free(txt);
        exit(0);
    }   

    execl("./3_pipe.out", "software", NULL);
}