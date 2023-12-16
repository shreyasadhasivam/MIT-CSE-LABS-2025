#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fa,*fb;
	int ca,cb;
	fa = fopen("q4in.c","r");
	if(fa==NULL)
	{
		printf("Cannot open file\n");
		exit(0);
	}
	fb= fopen("q4out.c","w");
	ca =getc(fa);
	while(ca!=EOF)
	{
		if(ca=='#')
		{
			while(ca!='>'||ca=='\n')
				ca=getc(fa);
		}
		else putc(ca,fb);
		ca = getc(fa);
	}
	fclose(fa);
	fclose(fb);
	return 0;
}