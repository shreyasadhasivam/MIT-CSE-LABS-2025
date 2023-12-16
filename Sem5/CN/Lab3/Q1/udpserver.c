#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<netinet/in.h>
#define PORT 10204
#define MAXLINE 1000
  
// Driver code
int main()
{   
    //char buffer[100];
    int arr1[10], arr2[10],arr3[10];
    //char *message = "Hello Client";
    int listenfd, len;
    struct sockaddr_in servaddr, cliaddr;
    bzero(&servaddr, sizeof(servaddr));
  
    // Create a UDP Socket
    listenfd = socket(AF_INET, SOCK_DGRAM, 0);        
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET; 
   
    // bind server address to socket descriptor
    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
       
    //receive the datagram
    len = sizeof(cliaddr);
    int n1 = recvfrom(listenfd, arr1, sizeof(arr1),
            0, (struct sockaddr*)&cliaddr,&len); //receive message from server
    arr1[n1] = '\0';
    //puts(arr);
    int mat[3][3];
    for(int i=0;i<3;i++)
    {
        mat[0][i]= arr1[i];
    }
    // mat[0][0]=arr1[0];
    // mat[0][1]=arr1[1];
    // mat[0][2]=arr1[2];
    int n2 = recvfrom(listenfd, arr2, sizeof(arr2),
            0, (struct sockaddr*)&cliaddr,&len);
    arr2[n2]='\0';
    for(int i=0;i<3;i++)
    {
        mat[1][i]= arr2[i];
    }
    // mat[1][0]= arr2[0];
    // mat[1][1]= arr2[1];
    // mat[1][2]=arr2[2];
    int n3 = recvfrom(listenfd, arr3, sizeof(arr3),
            0, (struct sockaddr*)&cliaddr,&len);
    arr3[n3]='\0';
    for(int i=0;i<3;i++)
    {
        mat[2][i]= arr3[i];
    }
    // mat[2][0] = arr3[0];
    // mat[2][1]= arr3[1];
    // mat[2][2]= arr3[2];
    printf("The matrix is:\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t", mat[i][j]);

        }
        printf("\n");
    }
    printf("\n");
           
    // send the response
    //sendto(listenfd, message, MAXLINE, 0,
          //(struct sockaddr*)&cliaddr, sizeof(cliaddr));
}