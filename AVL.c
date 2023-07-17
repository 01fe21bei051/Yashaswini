#include <stdio.h>
#include <stdlib.h>

// AVL tree node structure
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to get the height of a node
int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node with the given key
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* findMinimum(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->key) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->key) {
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
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

// Function to right rotate a subtree rooted with y
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
struct Node* insert(struct Node* node, int key) {
    // Perform the normal BST insertion
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicate keys are not allowed in AVL tree
        return node;

    // Update the height of the ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // No imbalance, return the unchanged node pointer
    return node;
}

struct Node* balance(struct Node* node, int key) {
    // Check the balance factor and rebalance if needed
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
    {
        printf("\nImplementing RR rotation\n");
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key)
    {
        printf("\nImplementing LL rotation\n");
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        printf("\nImplementing LR rotation\n");
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        printf("\nImplementing RL rotation\n");
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // No imbalance, return the unchanged node pointer
    return node;
}

// Function to print the inorder traversal of the AVL tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Driver program
int main() {
    struct Node* root = NULL;
    FILE* file1 = fopen("input.txt", "r");
    int ch, data, treeHeight, key,value;
    while(1)
    {
        printf("\n1--Take input from file");
        printf("\n2--balance the AVL tree");
        printf("\n3--display");
        printf("\n4--Find height");
        printf("\n5--Find balance factor");
        printf("\n6--Find root");
        printf("\n7--delete");
        printf("\n8--exit\n");
        printf("\n\nEnter your choice=\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                 if (file1 == NULL) {
                 printf("Error opening the file.\n");
                 return 1;
                   }
               while (fscanf(file1, "%d", &data) != EOF) {
               root = insert(root, data);
               }
                  fclose(file1);
                printf("\nBST is formed\n");
                break;

            case 2:root=balance(root, root->key);
                     break;

            case 3:printf("\nAVL tree: ");
                   inorderTraversal(root);
                   break;

            case 4:treeHeight = height(root);
                   printf("\nHeight of the AVL tree is: %d\n", treeHeight);
                   break;

            case 5:printf("\nBalance factor of the AVL tree is: %d\n", getBalance(root));
                   break;

            case 6:printf("\nThe root is= %d\n",root->key);
                   break;

            case 7:printf("Enter the value to delete: ");
                 scanf("%d", &value);
                 root = deleteNode(root, value);
                 break;

            case 8:exit(0);
                   break;

            default: printf("\nInvalid choice\n");
        }
    }
    return 0;
}
