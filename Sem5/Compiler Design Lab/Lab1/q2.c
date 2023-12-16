#include<stdio.h>
#include<stdlib.h>

int main()
{
	char name[100];
	char c;
	int nchar;
	int offset =-1;
	FILE *ptr1, *ptr2;
	printf("Enter the name of the file: ");
	scanf("%s", name);
	ptr1 = fopen(name, "r");
	if(ptr1 == NULL)
	{
		printf("The file does not exist.");
		exit(0);
	}

	printf("Enter the file name for storing: ");
	scanf("%s", name);
	ptr2 = fopen(name , "w+");
	fseek(ptr1, 0, SEEK_END);//if offset is 0, then it'll go to EOF therefore set offeset to -1
	nchar = ftell(ptr1);
	printf("The size of the file is:%d", nchar);
	//c = fgetc(ptr1);
	//printf("%c", c);
	nchar = nchar*-1;
	while(offset>=nchar)
	{
		fseek(ptr1,offset,SEEK_END);
		c = fgetc(ptr1);
		fputc(c,ptr2);
        //printf("%c", fputc(c,ptr2));
		offset--;		
	}
	printf("\nContents copied in reverse to %s.\n",name);
	fclose(ptr1);
	fclose(ptr2);
	return 0;
}