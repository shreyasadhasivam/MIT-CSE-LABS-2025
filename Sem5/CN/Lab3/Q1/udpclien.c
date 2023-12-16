#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
  
#define PORT 10204
#define MAXLINE 1000
  
// Driver code
int main()
{   
    char buffer[100];
    char *message = "Hello Server";
    int rows, cols;
    int sockfd, n;
    struct sockaddr_in servaddr;
      
    // clear servaddr
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_addr.s_addr = inet_addr("172.16.48.50");
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;
      
    // create datagram socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
      
    // connect to server
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("\n Error : Connect Failed \n");
        exit(0);
    }
    //printf("Enter the number of rows:");
    //scanf("%d", &rows);
    //printf("\nEnter the number of cols:");
    //scanf("%d", &cols);
    printf("Enter the elements of first row:\n");
    int arr1[3];
    for(int i=0;i<3;i++)
    {
        scanf("%d", &arr1[i]);
    }
    int arr2[3];
    printf("Enter the elements of second row:\n");
    for(int i=0;i<3;i++)
    {
        scanf("%d", &arr2[i]);
    }
    int arr3[3];
    printf("Enter the elements of third row:\n");
    for(int i=0;i<3;i++)
    {
        scanf("%d", &arr3[i]);
    }
    // request to send datagram
    // no need to specify server address in sendto
    // connect stores the peers IP and port
    sendto(sockfd, arr1, MAXLINE, 0, (struct sockaddr*)NULL, sizeof(servaddr));
    sendto(sockfd, arr2, MAXLINE, 0, (struct sockaddr*)NULL, sizeof(servaddr));
    sendto(sockfd, arr3, MAXLINE, 0, (struct sockaddr*)NULL, sizeof(servaddr));
    // waiting for response
    //recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)NULL, NULL);
    //puts(buffer);
  
    // close the descriptor
    close(sockfd);
}