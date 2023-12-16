#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 10204

int main()
{
	int sockfd, newsockfd,portno, clilen, n=1;
	struct sockaddr_in seraddr, cliaddr;
	int i,value;

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("172.16.48.89");
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd,(struct sockaddr*)&seraddr, sizeof(seraddr));

	listen(sockfd,5);
	while(1)
	{
		char buf[256];
		printf("Server waiting\n");
		clilen = sizeof(clilen);
		newsockfd = accept(sockfd,(struct sockaddr*)&cliaddr,&clilen);
		n = read(newsockfd, buf, sizeof(buf));
		printf("Encrypted Message from client %s\n", buf);
		n = write(newsockfd, buf,sizeof(buf));
		printf("Decyrpting message...\n");
		for(int i=0;i<256;i++)
		{
			buf[i]= buf[i]-4;
		}
		printf("Decrypted messafe is: %s\n", buf);
		n = write(newsockfd, buf,sizeof(buf));

		exit(0);
	}
	close(newsockfd);
	close(sockfd);
	return 0;
}