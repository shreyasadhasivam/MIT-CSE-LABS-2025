
#include <stdio.h>
#include <string.h>

void search(char* pat, char* txt)
{
	int m = strlen(pat);
	int n = strlen(txt);

	for (int i = 0; i <= n - m; i++) {
		int j;

		
		for (j = 0; j < m; j++)
			if (txt[i + j] != pat[j])
				break;

		if (j== m)
			printf("Pattern found at index %d \n", i);
	}
}


int main()
{
	char txt[10];
	char pat[10];
	printf("Enter string: ");
	scanf("%s", txt);
	printf("Enter substring: ");
	scanf("%s", pat);


	
	
	search(pat, txt);
	return 0;
}
