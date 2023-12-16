#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
bool isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}
void parse(char* str)
{
    int left = 0, right = 0;
    int len = strlen(str);
 
    while (right <= len && left <= right) {
        if (isDelimiter(str[right]) == false)
            right++;
 
        if (isDelimiter(str[right]) == true && left == right) {
            if (isOperator(str[right]) == true)
                printf("'%c' IS AN OPERATOR\n", str[right]);
 
            right++;
            left = right;
        } else if (isDelimiter(str[right]) == true && left != right
                   || (right == len && left != right)) {
            char* subStr = subString(str, left, right - 1);
 
            if (isKeyword(subStr) == true)
                printf("'%s' IS A KEYWORD\n", subStr);
 }
int main()
{
	FILE *fa,*fb;
	char ca,cb;
	fa = fopen("q4in.c","r");
	if(fa==NULL)
	{
		printf("Cannot open file\n");
		exit(0);
	}
	fb= fopen("q4out.c","w");
	ca =getc(fa);
	char str;
	char keywords[12] ={'if','else','else if','fopen','int','getc','putc','exit','return','char','while','do'};
	printf("%c", ca);
	while(ca!=EOF)
	{
		
		for(int i=0;i<12;i++)
		{
			if(ca==keywords[i])
			{
				str=keywords[i];
				toupper(str);
				putc(str,fb);
			}
		}
		putc(ca,fb);
		ca = getc(fa);
	}
	fclose(fa);
	fclose(fb);
	return 0;
}
