#include"gluchytelefon.h"
#include"1_konsola.h"

int main(){
    long int value = 0;

    logger(INFO, "1. Konsola (x:=modulo 10)");
    while (true){
        printf("Enter number between 0 and %u: ", UINT_MAX);
        if (scanf("%ld", &value)){
            if(!checkRange(value)){
                logger(ERROR, "OUT OF RANGE");
                continue;
            }

            printf("[INPUT] %ld\n", value);

            value = transform(value);

            if(!checkRange(value)){
                logger(ERROR, "OUT OF RANGE");
                continue;
            }
            printf("[OUTPUT] %ld\n", value);

            send((unsigned int) value);
        }
        else{
            scanf("%*s");
            logger(ERROR, "INCORRECT CHARACTERS");
        }
    }
    return 0;
}

long int transform(long int value){
    return value % 10;
}

void send(const unsigned int value){
    char * command = NULL;
    asprintf(&command, "./2_argument.out -i %d", value);
    system(command);
    free(command);
}
