#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 10200

int main() {
    int sockfd, result;
    struct sockaddr_in server_addr;
    int arr[10];
    int sorted_arr[10];
    int process_id;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("172.16.48.89");
    server_addr.sin_port = htons(PORT);

    result = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (result == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Enter 10 integers: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    write(sockfd, arr, sizeof(arr));

    read(sockfd, sorted_arr, sizeof(sorted_arr));
    read(sockfd, &process_id, sizeof(process_id));

    printf("Sorted array received from server: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");
    printf("Process ID received from server: %d\n", process_id);

    close(sockfd);

    return 0;
}