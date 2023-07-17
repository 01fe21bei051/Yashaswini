#include <stdio.h>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int part(int arr[], int low, int high)
{
    int p = arr[high];
    int i = (low - 1);
  for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < p)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = part(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    int i,N,arr[100];
    printf("Enter the set");
    scanf("%d",&N);
    printf("The no's are:");
    for(i=0;i<N;i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<N;i++)
    {
        quickSort(arr, 0, N - 1);
        printf("%d",arr[i]);
    }
    return 0;
}
