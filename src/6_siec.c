#include "6_siec.h"
#include "gluchytelefon.h"


int main(int argc, char * argv[]){
    printf("[INFO] 6. Siec (stdout na osobnej konsoli)\n");

    long int number = receive();

    printf("[INPUT] %ld\n", number);

    nsend(number);

    return 0;
}

long int receive(){
    int cli_socket;
    struct sockaddr_in srv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    cli_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(cli_socket == -1){
        perror("Socket error");
        exit(1);
    }

    server = gethostbyname(TCP_HOST);

    if(server == NULL){
        perror("gethostbyname");
        exit(1);
    }

    memset(&srv_addr, 0, sizeof(srv_addr));
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(TCP_PORT);
    memcpy(&srv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if(connect(cli_socket, (struct sockaddr *) &srv_addr, sizeof(srv_addr)) == -1){
        perror("Connect error");
        exit(1);
    }

    if(read(cli_socket, buffer, sizeof(buffer)) == -1){
        perror("Read error");
        exit(1);
    }

    close(cli_socket);
    return atol(buffer);
}

void nsend(const long int number)
{
    pid_t pid;
    if ((pid = fork()) == -1)
    {
        perror("Fork error");
        exit(0);
    }
    else
    {
        if (pid == 0)
        {
            char * txt = NULL;
            if (checkRange(number))
            {
                asprintf(&txt, "%ld", number);
            }
            else
            {
                printf("[ERROR] Out of range\n");
            }
            execl("/usr/bin/xterm", "xterm", "-hold", "-e", "echo", txt, NULL);
            free(txt);
        }
    }
}