
#include<stdio.h>


int gcd(int m, int n)

{
	int t = (m<n) ? m : n;

	
	int opcount =0;
	
	// int arr[2];

	while(t-->0)
	{
		opcount ++;
		if(m%t==0)

		{
			if(n%t==0)
			{
				// arr[0] = t;
				printf("The operational count is %d\n", opcount);
				return t;

			}
			
		}
	}
	// arr[1]= opcount;
	// return arr;
//	printf("The operational count is %d", opcount);

}

int main()
{
	int m,n;
	printf("Enter m:");

	scanf("%d", &m);
	printf("Enter n:");

	scanf("%d", &n);
	// int ans[2];
	// ans = gcd(m,n);

	// printf("%d %d", ans[0], ans[1]);

	printf("The GCD using consecutive integer checking method is:%d\n", gcd(m,n));



}