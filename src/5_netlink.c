#include "gluchytelefon.h"
#include "5_netlink.h"

int main(int argc, char * argv[]){
    logger(INFO, "[PLACEHOLDER] 5. Netlink (x:= suma cyfr liczby x w postaci dziesiętnej)");

    long int number = parse_args(argc, argv);

    printf("[INPUT] %ld\n", number);

    number = transform(number);

    printf("[OUTPUT] %ld\n", number);

    n_send(number);

    return 0;
}

long int transform(long int value){
    int t, sum = 0, rem;

    t = value;

    while(t != 0){
        rem = t % 10;
        sum = sum + rem;
        t = t / 10;
    }   

    return sum;

}

long int parse_args(int argc, char * argv[]){
    // TODO, placeholder
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

void tcp_server(const unsigned int number){
    int srv_socket, cli_socket;
    struct sockaddr_in srv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addrlen;
    int yes = 1;

    if((srv_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("Socket error");
        exit(1);
    }

    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(TCP_PORT);
    srv_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(srv_addr.sin_zero), 0, sizeof(srv_addr));

    setsockopt(srv_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

    if(bind(srv_socket, (struct sockaddr *) &srv_addr, sizeof(srv_addr)) == -1){
        perror("Bind error");
        close(srv_socket);
        exit(1);
    }

    if(listen(srv_socket, 5) == -1){
        perror("Listen error");
        close(srv_socket);
        exit(1);
    }

    addrlen = sizeof(cli_addr);
    
    cli_socket = accept(srv_socket, (struct sockaddr *) &cli_addr, &addrlen);

    if(cli_socket == -1){
        perror("Accept error");
        close(srv_socket);
        exit(1);
    }

    sprintf(buffer, "%u", number);

    if(write(cli_socket, buffer, sizeof(buffer)) == -1){
        perror("Write error");
        exit(1);
    }


    close(srv_socket);
    close(cli_socket);

}

void n_send(const unsigned int value){
    pid_t pid;

    pid = fork();

    if(pid == -1){
        perror("Fork error");
        exit(0);
    }else{
        if(pid == 0){
            tcp_server(value);
            exit(0);
        }
    }
    execl("./6_siec.out", "software", NULL);
}