#include"gluchytelefon.h"

bool checkRange(const long int value){
    if (value > 0 && value < UINT_MAX){
        return true;
    }
    return false;
}

void logger(infoType type, char msg[]){
    switch (type)
    {
        case ERROR:
            printf("[ERROR] %s\n", msg);
            break;

        case INPUT:
            printf("[INPUT]  %s\n", msg);
            break;

        case OK:
            printf("[OK] %s\n", msg);
            break;

        case OUTPUT:
            printf("[OUTPUT] %s\n", msg);
            break;
    }
}