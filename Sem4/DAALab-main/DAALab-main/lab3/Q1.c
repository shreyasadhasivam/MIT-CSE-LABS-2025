#include<stdio.h>
 
int opcount =0;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int arr[], int n)
{
	//int *opc =0;
	for(int i=0;i<n-1;i++)
	{

		for(int j=0;j<n-1-i;j++)
		{
			//opcount++;
			if(arr[j+1]<arr[j])
			{
				//(*opc)++;
				opcount++;
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

int main()
{
	int n, opc;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	int arr[n];
	printf("\nEnter the elements in the array: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("\nThe unsorted array is: ");
	for(int i=0;i<n;i++)
	{
		printf("%d ", arr[i]);
	}
	bubbleSort(arr, n);
	printf("\nThe sorted array is: ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}

	printf("\nOperational count:%d\n", opcount);
	return 0;

}
