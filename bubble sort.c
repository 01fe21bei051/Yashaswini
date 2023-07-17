#include<stdio.h>
void bubble(int a[],int n);
void main()
{
    int i,n;
    int a[100];
     //n = sizeof(a)/sizeof(a[0]);
    printf("Enter the no o value:");
    scanf("%d",&n);
    printf("The elements are:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("The sorted elements are:");
    for(i=0;i<n;i++)
    {
        bubble(a,n);
        printf("%d",a[i]);
    }


}

void bubble(int a[],int n)
{
    int i,j,temp;
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

}
