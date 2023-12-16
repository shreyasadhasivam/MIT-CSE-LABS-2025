#include<stdio.h>
#include<stdlib.h>

int main()
{
	char name[100];
	char c1,c2;
	FILE *file1,*file2, *file3;
	printf("Enter the name of file 1: ");
	scanf("%s", name);
	file1 = fopen(name, "r");
	printf("Enter the name of file 2: ");
	scanf("%s", name);
	file2 = fopen(name, "r");
	printf("Enter the name of file 3: ");
	scanf("%s", name);
	file3 = fopen(name, "w+");
	if(file1 == NULL || file2 == NULL)
	{
		printf("Merging is not possible.\n");
		exit(0);
	}
	else
	{
		printf("hi");
		while(c1!=EOF || c2!=EOF)
		{	
			printf("hello");
			c1=fgetc(file1);
			while(c1=='\n' && c1!=EOF)
			{
				printf("hola");
				c1=fgetc(file1);
				fputc(c1,file3);
			}
			c2=fgetc(file2);
			while(c2=='\n' && c2!=EOF)
			{
				printf("bonjour");
				c1=fgetc(file1);
				fputc(c2,file3);
			}

		}
	}
	printf("Merging done.\n");
	fclose(file1);
	fclose(file2);
	fclose(file3);
	return 0;
}