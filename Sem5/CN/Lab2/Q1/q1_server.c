#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define PORT 10200

void sortArray(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int sockfd, newsockfd, clilen, n;
    struct sockaddr_in server_addr, client_addr;
    int arr[10];
    int sorted_arr[10];
    int process_id;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    while (1) {
        clilen = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr*)&client_addr, &clilen);

        if (fork() == 0) {
            n = read(newsockfd, arr, sizeof(arr));

            sortArray(arr, 10);

            write(newsockfd, arr, sizeof(arr));
            process_id = getpid();
            write(newsockfd, &process_id, sizeof(process_id));

            close(newsockfd);
            exit(0);
        } else {
            close(newsockfd);
            wait(NULL);
        }
    }
    printf(" array received from client: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("Sorted array sent to client: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", sorted_arr[i]);
    }


    close(sockfd);

    return 0;
}