#include<stdio.h>
#include<stdlib.h>
void bubble(int n,int *a,FILE *f2)
{
    int i;
    printf("Bubble sort:");
   for(i=0;i<n;i++)
   {
       printf("%d",a[i]);
   }
   int j,temp;
   for(i=0;i<n;i++)
   {
       for(j=i+1;j<n;j++)
       {
          if(a[j]<a[i])
			{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			}
		}
       }
       printf("Output\t");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
		fprintf(f2,"%d ",a[i]);
	}
   }

   int main()
   {
       FILE *f1,*f2,*f3;
       int i,n,a[n],x,t;
       f1=fopen("INPUT.txt","w");
       f2=fopen("OUTPUT.txt","w");
       printf("The no's are:");
       for(i=0;i<n;i++)
       {
           scanf("%d",&a[i]);
       }
       f1=fopen("input.txt","r");
	printf("\n");
	for(i=0;i<n;i++)
	{
		fscanf(f1,"%d",&x);
		a[i]=x;
	}
	fclose(f1);
	fprintf(f3,"Bubble sorting takes %d sec\n",t);
	fprintf(f2,"\n");
   }

