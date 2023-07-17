#include <stdio.h>
#include <stdlib.h>

// Structure to represent a chessboard position
typedef struct Node {
    int row;
    int col;
    struct Node* next;
} Node;

// Function to create a new node with given coordinates
Node* createNode(int row, int col) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertNode(Node** head, int row, int col) {
    Node* newNode = createNode(row, col);
    newNode->next = *head;
    *head = newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("Coin position: (%d, %d)\n", temp->row, temp->col);
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;

    // Inserting nodes representing the position of the coin
    insertNode(&head, 2, 3);
    insertNode(&head, 4, 5);
    insertNode(&head, 6, 1);

    // Displaying the linked list
    displayList(head);

    return 0;
}

