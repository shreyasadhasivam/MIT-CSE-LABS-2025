#include<stdio.h>
//int opcount =0;
int main()
{
  int c, d, p, q, m, n, k, tot = 0;
  int fst[10][10], sec[10][10], mul[10][10];

  printf("Enter the rows and columns for matrix A: \n");
  scanf("%d%d", &m, &n);

  printf("Insert your matrix elements : \n");
  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      scanf("%d", &fst[c][d]);
 
  printf("Enter the rows and columns for matrix B: \n");
  scanf(" %d %d", &p, &q);

  if (n != p)
    printf("Multiplication is not possible\n");
  else
  {
    printf("Insert matrix elements \n");
 
    for (c = 0; c < p; c++)
      for (d = 0; d < q; d++)
        scanf("%d", &sec[c][d] );

    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++) {
        for (k = 0; k < p; k++) 
        {
        	//opcount++
          	tot = tot + fst[c][k] * sec[k][d];
        }
        mul[c][d] = tot;
        tot = 0;
      }
    }
 
    printf("The result of matrix multiplication: \n"); 
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++)
        printf("%d \t", mul[c][d] );
      printf(" \n ");
    }
  }
  return 0;
}
