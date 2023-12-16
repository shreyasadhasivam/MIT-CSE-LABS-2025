#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<ctype.h>
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
		char words[100][100];
		int i=0,j=0,k,length,count;
		printf("Server waiting\n");
		clilen = sizeof(clilen);
		newsockfd = accept(sockfd,(struct sockaddr*)&cliaddr,&clilen);
		n = read(newsockfd, buf, sizeof(buf));
		printf("Message from client %s\n", buf);
		n = write(newsockfd, buf,sizeof(buf));
		for(k=0;buf[k]!='\0';k++){
			if(buf[k]!=' ' && buf[k]!='\0')
			{
				words[i][j++] = tolower(buf[k]);
			}
			else{
				words[i][j]='\0';
				i++;
				j=0;
			}
		}
		length = i+1;
		printf("Duplicate words in the given string: \n");
		for(i=0;i<length;i++)
		{
			for(j=0;j<length;j++)
			{
				if(strcmp(words[i],words[j])==0 && (strcmp(words[j],"0")!=0))
				{
					count++;
					strcpy(words[j],"0");
				}
			}
			if(count>1)
				printf("%s\n", words[i]);
				n = write(newsockfd, words, sizeof(words));
		}
		//exit(0);
	}
	close(sockfd);
	return 0;
}