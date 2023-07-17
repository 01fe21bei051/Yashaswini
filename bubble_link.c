#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} Node;

struct Node* swap(struct Node* ptr1, struct Node* ptr2)
{
    struct Node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}
int bubbleSort(struct Node** head, int count)
{
    struct Node** h;
    int i, j, swapped,n,arr[100];

    for (i = 0; i <= count; i++) {

        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++) {

            struct Node* p1 = *h;
            struct Node* p2 = p1->next;

            if (p1->data > p2->data) {
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }
        if (swapped == 0)
            break;
    }
   /* printf("Output\t");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
		fprintf(f2,"%d ",arr[i]);
	}*/
}
void printList(struct Node* n)
{
    while (n != NULL) {
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("\n");
}

void insertAtTheBegin(struct Node** start_ref, int data)
{
    struct Node* ptr1
        = (struct Node*)malloc(sizeof(struct Node));

    ptr1->data = data;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}


int main()
{
    int n, i,arr[10],x;
   // FILE *f1,*f2,*f3;
    //f1=fopen("inputs.txt","w");
   // f2=fopen("results.txt","w");
   // f3=fopen("in.txt","w");
    struct Node* start = NULL;
    n = sizeof(arr) / sizeof(arr[0]);
printf("Enter the set");
scanf("%d",&n);
printf("The elements are:");
for(i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
    insertAtTheBegin(&start, arr[i]);
}/*fclose(f1);
f1=fopen("input.txt","r");
	printf("\n");
	for(i=0;i<n;i++)
	{
		fscanf(f1,"%d",&x);
		arr[i]=x;
	}fclose(f1);
	printf("Read from file\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
	//fprintf(f2,"Bubble sort\n");*/
bubbleSort(&start,n);
    printf("After sorting:\n");
    printList(start);

    return 0;
}
