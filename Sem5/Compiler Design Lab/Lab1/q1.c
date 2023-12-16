#include<stdio.h>
#include<stdlib.h>

int main()
{
	char filename[100];
	char c;
	int nchar=0;
	int nlines=0;
	FILE *fptr;
	printf("Enter the filename: ");
	scanf("%s", filename);
	fptr = fopen(filename,"r");
	if(fptr==NULL)
	{
		printf("The file does not exist.");
		exit(0);
	}
	c = fgetc(fptr);
	while(c!=EOF)
	{
		c=fgetc(fptr);
		if(c!=' ' && c!='\n')
		{
			nchar++;
		}
		else if(c=='\n')
		{
			nlines++;
		}
	}
	printf("The number of characters are: %d\n", nchar);
	printf("The number of lines are: %d\n", nlines);
	fclose(fptr);
	return 0;
}