#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

// Graph data structure
struct Graph {
    int numVertices;
    int** adjMatrix;
};

// Stack data structure
struct Stack {
    int top;
    int items[MAX_VERTICES];
};

// Queue data structure
struct Queue {
    int front;
    int rear;
    int items[MAX_VERTICES];
};

// Function prototypes
struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest);
void bfs(struct Graph* graph, int startVertex);
void dfs(struct Graph* graph, int startVertex);
void push(struct Stack* stack, int value);
int pop(struct Stack* stack);
int isStackEmpty(struct Stack* stack);
void enqueue(struct Queue* queue, int value);
int dequeue(struct Queue* queue);
int isQueueEmpty(struct Queue* queue);

int main() {
    char filename[] = "input1.txt";
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    int numVertices;
    fscanf(file, "%d", &numVertices);
    printf("NumVertices= %d\n",numVertices);

    struct Graph* graph = createGraph(numVertices);

    int src, dest;
    while (fscanf(file, "%d %d", &src, &dest) == 2) {
            printf("src=%d  dest=%d\n",src,dest);
        addEdge(graph, src, dest);
    }

    fclose(file);

    printGraph(graph);
    printf("BFS traversal: ");
    bfs(graph, 0);
    printf("\n");

    printf("DFS traversal: ");
    dfs(graph, 0);
    printf("\n");
    return 0;
}

// Function to create a graph with given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->adjMatrix = (int*)malloc(numVertices * sizeof(int));
    int i, j;
    for (i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(numVertices * sizeof(int));
        for (j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        graph->adjMatrix[src][dest] = 1;
        graph->adjMatrix[dest][src] = 1;
    }
}

// Breadth-First Search (BFS) traversal
void bfs(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;

    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isQueueEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
}

// Depth-First Search (DFS) traversal
void dfs(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;

    visited[startVertex] = 1;
    push(stack, startVertex);

    while (!isStackEmpty(stack)) {
        int currentVertex = pop(stack);
        printf("%d ", currentVertex);

        for (i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                push(stack, i);
            }
        }
    }
}

// Function to push an element into the stack
void push(struct Stack* stack, int value) {
    stack->top++;
    stack->items[stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    int value = stack->items[stack->top];
    stack->top--;
    return value;
}

// Function to check if the stack is empty
int isStackEmpty(struct Stack* stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int value) {
    if (isQueueEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = value;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    return value;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue* queue) {
    if (queue->rear == -1) {
        return 1;
    }
    return 0;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    int i, j;
    for (i = 0; i < graph->numVertices; i++) {
        for (j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
