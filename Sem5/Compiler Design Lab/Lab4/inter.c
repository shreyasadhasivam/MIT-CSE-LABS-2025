
void printArray(int array[], int size){
	for(int i= 0;i<=size;++i)
	{
		printf("%d ",array[i]);

	}
	printf("\n");
}

int main()
{
	int data[] ={2,45,0,11,9};

	//find the array's length
	int size = sizeof(data)/sizeof(data[0]);

	printf("Entered array   :\n");
	printArray(data,size);

}