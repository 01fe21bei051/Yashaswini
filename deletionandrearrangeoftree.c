#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

struct Node* createNode(int data)
 {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int height(struct Node* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node* insert(struct Node* root, int data)
{
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

struct Node* findMinimum(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int data)
 {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {

        root->right = deleteNode(root->right, data);
    } else {
        // Case 1: No child or only one child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Two children
        struct Node* temp = findMinimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Function to left rotate a subtree rooted with x
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Function to get the balance factor of a node
int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to insert a node into the AVL tree

struct Node* balance(struct Node* node, int data) {
    // Check the balance factor and rebalance if needed
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
    {
        printf("\nImplementing RR rotation\n");
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && data > node->right->data)
    {
        printf("\nImplementing LL rotation\n");
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        printf("\nImplementing LR rotation\n");
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        printf("\nImplementing RL rotation\n");
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // No imbalance, return the unchanged node pointer
    return node;
}


void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value, treeHeight;
    char filename[100];
    FILE* file;

    printf("Binary Search Tree\n");



    // Open the file
    file = fopen("E:\\tree(del).txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Read the numbers from the file and insert them into the tree
    while (fscanf(file, "%d", &value) != EOF) {
        root = insert(root, value);
    }

    fclose(file);

    do {
        printf("\n1. Delete:");
        printf("\n2--balance the AVL tree");
        printf("\n3--display");
        printf("\n4--Find height");
        printf("\n5--Find balance factor");
        printf("\n6--Find root");
        printf("\n7--exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 2:root=balance(root, root->data);
                     break;

            case 3:printf("\nAVL tree: ");
                   inorderTraversal(root);
                   break;

            case 4:treeHeight = height(root);
                   printf("\nHeight of the AVL tree is: %d\n", treeHeight);
                   break;

            case 5:printf("\nBalance factor of the AVL tree is: %d\n", getBalance(root));
                   break;

            case 6:printf("\nThe root is= %d\n",root->data);
                   break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
