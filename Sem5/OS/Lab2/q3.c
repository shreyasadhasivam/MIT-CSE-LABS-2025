#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
int main(void)
{
	struct dirent **dp;
	int n;
	int i=0;
	n = scandir(".", &dp, 0, alphasort);
	if (n < 0)
	perror("scandir");
	else {
		while (i<n) {
			printf("%s\n", dp[i]->d_name);
			free(dp[i]);
			i++;
		}
	free(dp);
	}
}