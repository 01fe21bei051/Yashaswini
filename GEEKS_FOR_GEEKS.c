#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 10000

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Structure to represent the adjacency list
struct AdjList {
    struct Node* head;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct AdjList* array;
};

// Function to create a new node
struct Node* createNode(int vertex, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Create an array of adjacency lists
    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));

    // Initialize each adjacency list as empty
    for (int i = 0; i < numVertices; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge to a directed graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool visited[], int numVertices) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < numVertices; ++v) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to compute the shortest distances using Dijkstra's algorithm
int* shortestDistances(struct Graph* graph, int src) {
    int numVertices = graph->numVertices;
    int* dist = (int*)malloc(numVertices * sizeof(int));
    bool* visited = (bool*)malloc(numVertices * sizeof(bool));

    // Initialize all distances as infinite and visited array as false
    for (int v = 0; v < numVertices; ++v) {
        dist[v] = INT_MAX;
        visited[v] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    for (int count = 0; count < numVertices - 1; ++count) {
        // Pick the vertex with the minimum distance value from the set of vertices not yet processed
        int u = minDistance(dist, visited, numVertices);
        visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        struct Node* currentNode = graph->array[u].head;
        while (currentNode != NULL) {
            int v = currentNode->vertex;
            int weight = currentNode->weight;

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;

            currentNode = currentNode->next;
        }
    }

    free(visited);
    return dist;
}

// Function to free the memory allocated for the graph
void freeGraph(struct Graph* graph) {
    if (graph == NULL)
        return;

    for (int v = 0; v < graph->numVertices; ++v) {
        struct Node* currentNode = graph->array[v].head;
        while (currentNode != NULL) {
            struct Node* temp = currentNode;
            currentNode = currentNode->next;
            free(temp);
        }
    }

    free(graph->array);
    free(graph);
}

int main() {
    int V, S;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    struct Graph* graph = createGraph(V);

    printf("Enter the adjacency list representation of the graph:\n");
    for (int i = 0; i < V; ++i) {
        int numEdges;
        printf("Enter the number of edges for vertex %d: ", i);
        scanf("%d", &numEdges);

        printf("Enter the destination vertex and weight for each edge:\n");
        for (int j = 0; j < numEdges; ++j) {
            int dest, weight;
            scanf("%d %d", &dest, &weight);
            addEdge(graph, i, dest, weight);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &S);

    int* distances = shortestDistances(graph, S);

    printf("Shortest distances from source vertex %d:\n", S);
    for (int i = 0; i < V; ++i) {
        printf("Vertex %d: %d\n", i, distances[i]);
    }

    free(distances);
    freeGraph(graph);

    return 0;
}
