#include <stdio.h>
//int opcount =0;
void towerOfHanoi(int n, char source, char dest, char aux)
{

	if (n == 1)
	{

		printf("\n Move disk 1 from rod %c to rod %c", source, dest);
		return;
	}
	//opcount++;
	towerOfHanoi(n-1, source, aux, dest);
	printf("\n Move disk %d from rod %c to rod %c", n, source,dest);
	//opcount++;
	towerOfHanoi(n-1, aux, dest,source);
}

int main()
{
	printf("Enter number of discs: ");
	int n;
	scanf("%d", &n);
	towerOfHanoi(n, 'A', 'C', 'B'); 
	//printf("\nOperational count: %d\n", opcount);
	return 0;
}
