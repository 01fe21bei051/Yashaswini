#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#define queue_size 100
#define queue_file "QUEUE.txt"
#define enqueue_file "ENQUEUE.txt"
#define dequeue_file "DEQUEUE.txt"
#define operation_file "OPERATIONFILE.txt"
#define lqueue_file "LQUEUE.txt"
typedef struct
{
    int data[queue_size];
    int front;
    int rear;
}Queue;

void initqueue(Queue *queue)
{
    queue->front=-1;
    queue->rear=-1;
}

int isQueueFull(Queue *queue)
{
    return queue->rear==queue_size-1;
}

int isQueueEmpty(Queue *queue)
{
    return queue->front==-1;
}

void Enqueue(Queue *queue,int item)
{
    if(queue->rear==queue_size-1)
    {
        printf("Overflow\n");
        //return;
    }
    else
    {
        if(queue->front==-1)
        queue->front=0;
        queue->rear++;
    queue->data[queue->rear]=item;
    }

}

int Dequeue(Queue *queue)
{
    if(queue->front==-1)
       {
           printf("Underflow\n");
           return;
       }
        //printf("Element deleted from the Queue: %d\n", queue->data[queue->front]);
       queue->front++;
}

void display(Queue *queue)
{
    int i;
    if(queue->front==-1)

        printf("Queue is Empty");

    else
    {
        printf("The Queue contents are:");
        for(i=queue->front;i<=queue->rear;i++)
        {
            printf("%d",queue->data[i]);
        }
        printf("\n");
    }
}
void L_Queue(Queue *queue)
{
    int i;
    FILE *f=fopen("E://LQUEUE.txt","a");
    fprintf(f, "Queues contents: ");
    for (i = queue->front; i <= queue->rear; i++) {
        fprintf(f, "%d ", queue->data[i]);
    }
    fprintf(f, "\n");
    fclose(f);
}
void Enqueue_f(int item)
{
    FILE *f=fopen("E://ENQUEUE.txt","a");
    fprintf(f,"Enqueued elements:%d\n",item);
    fclose(f);
}

void Dequeue_f(int item)
{
    FILE *f=fopen("E://DEQUEUE.txt","a");
    fprintf(f,"Dequeued element:%d\n",item);
    fclose(f);
}

void operation_f(char *Operation)
{
    FILE *f=fopen("E://OPERATIONFILE.txt","a");
    fprintf(f, "%s\n", Operation);
    fclose(f);
}

int main()
{
    Queue queue;
    initqueue(&queue);
    FILE *f=fopen("E://LQUEUE.txt","w");
    fclose(f);
    int item,ch;
    char Operation[20];
    do
    {
       printf("1.ENQUEUE\n");
       printf("2.DEQUEUE\n");
       printf("3.DISPLAY\n");
       printf("4.QUIT\n");
       printf("Enter ur choice\n");
       scanf("%d",&ch);

       switch(ch)
       {
           case 1: printf("Enter the item to be enqueued");
           scanf("%d",&item);
           Enqueue(&queue,item);
           Enqueue_f(item);
           sprintf(Operation, "Enqueued item %d", item);
           operation_f(Operation);
           L_Queue(&queue);
           break;

           case 2: item= Dequeue
                             (&queue);
           if (item != -1) {
                printf("Dequeued item: %d\n",&item);
               Dequeue_f(item);
                sprintf(Operation, "Dequeued item %d",item);
                operation_f(Operation);
           }
           L_Queue(&queue);
           break;

           case 3:display(&queue);
           break;

           case 4:exit(0);
           break;

           default: printf("Invalid choice\n");
           break;
       }
    } while(ch!=4);
    return 0;

}
