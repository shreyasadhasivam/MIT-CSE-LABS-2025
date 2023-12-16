#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fa,*fb;
	int ca,cb;
	fa = fopen("testin.txt","r");
	if(fa==NULL)
	{
		printf("Cannot open file\n");
		exit(0);
	}
	fb = fopen("testout.txt","w");
	ca = getc(fa);
	while(ca!=EOF)
	{
		if(ca=='  ' ||ca =='\t')
		{
			while(ca!=' '&&ca!='\t')
				ca = getc(fa);
				
			//ca = getc(fa);
			
			fprintf(fb," ");
			
		}
		
		else
		{

			putc(ca,fb);
			
		}
		ca = getc(fa);
	}
	fclose(fa);
	fclose(fb);
	return 0;
}