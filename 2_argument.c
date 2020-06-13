#include"gluchytelefon.h"
#include"2_argument.h"

int main(int argc, char * argv[]){
    logger(INFO, "2. Argument (x:=nastepna liczba pierwsza)");
    char buffer[BUFFER_SIZE];

    int number = argv_to_int(argv[1]);
    long next_prime = find_prime(number);
 
    logger(INPUT, argv[1]);

    sprintf(buffer, "%ld", next_prime);
    logger(OUTPUT, buffer);

    return 0;
}

int argv_to_int(char * pchar){
    char * p;

    errno = 0;
    long conv = strtol(pchar, &p, 10);

    if (errno != 0 || *p != '\0' || conv > INT_MAX) {
        logger(ERROR, "INCORRECT CHARACTERS");
        return 0;
    }
    return conv;

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