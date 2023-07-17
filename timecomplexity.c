#include<stdio.h>

int main()
{
 int i,j,k,r1,c1,r2,c2;
CLOCK t1,t2,t;
int CLOCKS_PER_SEC;
 int low,high,n,a[n],r[n],x;
 printf("Enter the range and total numbers to be generated\n");
	scanf("%d %d %d",&low,&high,&n);
	srand(time(0));
 printf("Enter row and column of first matrix\n");
 scanf("%d%d", &r1, &c1);
 printf("Enter row and column of second matrix\n");
 scanf("%d%d", &r2, &c2);

 printf("Multiplication of matrix:");
 t1=clock();
 multiply(r1,c1,r2,c2);
 t2=clock();
 t=(t2-t1)/CLOCKS_PER_SEC;
}

void multiply(int r1, int c1, int r2, int c2)
{
    int i,j,k;
    float a[10][10],b[10][10],mult[10][10];
 if(c1=r2)
 {
     printf("Enter the no of elements\n");
     for(i=0;i<r1;i++)
     {
         for(j=0;j<c1;j++)
         {
             printf("a[%d][%d]",i,j);
             scanf("%f",&a[i][j]);
         }
     }
     printf("Enter the no of elements\n");
     for(i=0;i<r2;i++)
     {
         for(j=0;j<c2;j++)
         {
             printf("b[%d][%d]",i,j);
             scanf("%f",&b[i][j]);
             //printf("%d",b[i][j]);
         }
     }
     for(i=0;i<r1;i++)
     {

         for(j=0;j<c2;j++)
         {
             mult[i][j]=0;
             for(k=0;k<r2;k++)
             {
                 mult[i][j]+=a[i][k]*b[k][j];
             }
         }
     }
     printf("The multiplied elements are:\n");
     for(i=0;i<r1;i++)
     {
         for(j=0;j<c2;j++)
         {
             printf("%f\t",mult[i][j]);
         }
         printf("\n");
     }
     }
 else
 {
    printf("Dimensions doesn't match");
 }

 }

