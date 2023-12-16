#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main() {
    int sd;
    struct sockaddr_in address;
    sd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("172.217.160.174");
    address.sin_port = htons(80);

    int connect_status = connect(sd, (struct sockaddr*)&address, sizeof(address));
    if(connect_status < 0) {
        perror("connect");
        exit(1);
    }

    char *request = "GET / HTTP/1.1\r\nHost: www.youtube.com\r\n\r\n";
    int request_len = strlen(request);

    int bytes_sent = send(sd, request, request_len, 0);
    if (bytes_sent < 0) {
        perror("send");
        exit(1);
    }

    char response[4096];
    int bytes_received = recv(sd, response, sizeof(response)-1, 0);
    if (bytes_received < 0) {
        perror("recv");
        exit(1);
    }
    response[bytes_received] = '\0';

    printf("HTTP Response:\n%s\n", response);

    close(sd);

    return 0;
}