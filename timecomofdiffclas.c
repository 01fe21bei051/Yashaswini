#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int *a,int l,int h,int mid);

void mergesort(int *a,int l,int r,FILE *f2,int n)
{
	int m,i;
	if(l<r)
	{
		m=(l+r)/2;
		mergesort(a,l,m,f2,n);
		mergesort(a,m+1,r,f2,n);
		merge(a,l,r,m);
	}

}

void merge(int *a,int l,int r,int m)
{
	int b[1000];
	int i,j,k,c;
	i=l;
	j=m+1;
	k=l;
	while(i<=m && j<=r)
	{
		if(a[i]>a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=m)
	{
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<=r)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	for(c=l;c<=r;c++)
	{
		a[c]=b[c];
	}
}

void bubble(int n,int *a,FILE *f2)
{
	printf("Bubble\n");
	printf("Input\t");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
			k=a[j];
			a[j]=a[j+1];
			a[j+1]=k;
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

void select(int n,int *a,FILE *f2)
{
	printf("Select\n");
	printf("Input\t");
	int i,j,min,k;
	for(i=0;i<n;i++)
	{
		printf("%d \t",a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		min=i;
		//printf("min%d\n",min);
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
			min=j;
			}

}
			k=a[i];
			a[i]=a[min];
			a[min]=k;
		}
		printf("Output\t");
	for(i=0;i<n;i++)
	{
		printf("%d \t",a[i]);
		fprintf(f2,"%d \t",a[i]);
	}

}




int main()
{
	FILE *f1,*f2,*f3;
	clock_t t1,t2,t;
	f1=fopen("input.txt","w");
	f2=fopen("output.txt","w");
	f3=fopen("log.txt","w");
	int i,low,high,n,a[n],r[n],j,x;
	printf("Enter the range and total numbers to be generated\n");
	scanf("%d %d %d",&low,&high,&n);
	srand(time(0));
	for(i=0;i<n;i++)
	{
		r[i]=(rand()%(high-low+1))+low;
		fprintf(f1,"%d\n",r[i]);
	}fclose(f1);
	f1=fopen("input.txt","r");
	printf("\n");
	for(i=0;i<n;i++)
	{
		fscanf(f1,"%d",&x);
		a[i]=x;
	}fclose(f1);
	printf("Read from file\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	fprintf(f2,"Bubble sort\n");
	t1=clock();
	bubble(n,a,f2);
	t2=clock();
	t=(t2-t1)/CLOCKS_PER_SEC;
	fprintf(f3,"Bubble sorting takes %d sec\n",t);
	fprintf(f2,"\n");
	fprintf(f2,"Selection sort\n");
		printf("\n");
	t1=clock();
	select(n,a,f2);
	t2=clock();
	t=(t2-t1)/CLOCKS_PER_SEC;
	fprintf(f3,"Selection sorting takes %d sec\n",t);
		printf("\n");
		printf("Merge\n");
	printf("Input\t");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	fprintf(f2,"\n");
	fprintf(f2,"Merge sort\n");
	t1=clock();
	mergesort(a,0,n-1,f2,n);
	t2=clock();
	t=(t2-t1)/CLOCKS_PER_SEC;
	fprintf(f3,"Merge sorting takes %d sec\n",t);
		printf("Output\t");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
		fprintf(f2,"%d ",a[i]);
	}

	fclose(f2);
	fclose(f3);
}

