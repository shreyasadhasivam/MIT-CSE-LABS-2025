#include <stdio.h>

int main()

{
	int arr[5];
	int sum = 0;
	printf("Enter the elements of the array: ");
	for(int i=0;i<5;i++)
	{
		scanf("%d", &arr[i]);

	}
	for(int i=0;i<5;i++)
	{
		sum += arr[i];
	}

	if(sum%2 == 0)
	{
		printf("Success\n");
	}
	else
		return -1;
}