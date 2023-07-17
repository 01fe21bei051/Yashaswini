



























#include<stdio.h>

void multiply(int r1, int c1, int r2, int c2);

int main()
{
 int i,j,k,r1,c1,r2,c2;

 printf("Enter row and column of first matrix\n");
 scanf("%d%d", &r1, &c1);
 printf("Enter row and column of second matrix\n");
 scanf("%d%d", &r2, &c2);
 multiply(r1,c1,r2,c2);
 return 0;
}

void multiply(int r1, int c1, int r2, int c2)
{
 int i,j,k;
 float a[10][10], b[10][10], mul[10][10];
 if(c1==r2)
 {
  printf("Enter elements of first matrix:\n");
  for(i=0;i< r1;i++)
  {
   for(j=0;j< c1;j++)
   {
    printf("a[%d][%d]=",i,j);
    scanf("%f", &a[i][j]);
   }
  }
  printf("Enter elements of second matrix:\n");
  for(i=0;i< r2;i++)
  {
   for(j=0;j< c2;j++)
   {
    printf("b[%d][%d]=",i,j);
    scanf("%f", &b[i][j]);
   }
  }
  for(i=0;i< r1;i++)
  {
   for(j=0;j< c2;j++)
   {
    mul[i][j] = 0;
    for(k=0;k< r2;k++)
    {
     mul[i][j] = mul[i][j] + a[i][k]*b[k][j];
    }
   }
  }
  printf("Multiplied matrix is:\n");
  for(i=0;i< r1;i++)
  {
   for(j=0;j< c2;j++)
   {
    printf("%f\t", mul[i][j]);
   }
   printf("\n");
  }
 }
 else
 {
  printf("Dimension do not match for multiplication.");
 }
}
