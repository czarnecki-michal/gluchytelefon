#include"gluchytelefon.h"
#include"1_konsola.h"

int main(){
    long int value = 0;

    printf("1.konsola, x:=modulo 10\n");
    while (true){
        printf("Enter number between 0 and %u: ", UINT_MAX);
        if (scanf("%ld", &value)){
            char buffer[BUFFER_SIZE];
            if(!checkRange(value)){
                logger(ERROR, "OUT OF RANGE");
                continue;
            }
            value = transform(value);

            if(!checkRange(value)){
                logger(ERROR, "OUT OF RANGE");
                continue;
            }
            sprintf(buffer, "%ld", value);
            logger(OUTPUT, buffer);
        }
        else{
            scanf("%*s");
            logger(ERROR, "INCORRECT CHARACTERS");
        }
    }
}

long int transform(long int value){
    return value % 10;
}
