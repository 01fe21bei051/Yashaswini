#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}


void inorderTraversal(struct Node* root,FILE* file)
{
    int c=0;
    if (root != NULL)
    {
        inorderTraversal(root->left,file);
        printf("%d ", root->data);
        fprintf(file, "%d\n",root->data);
        inorderTraversal(root->right,file);
    }
}
void preorderTraversal(struct Node* root,FILE* file) {
    if (root != NULL)
    {
        printf("%d ", root->data);
        fprintf(file, "%d\n",root->data);
        preorderTraversal(root->left,file);
        preorderTraversal(root->right,file);
    }
}
void postorderTraversal(struct Node* root,FILE* file) {
    if (root != NULL)
    {
        postorderTraversal(root->left,file);
        postorderTraversal(root->right,file);
        printf("%d ", root->data);
        fprintf(file, "%d\n",root->data);
    }
}

int NodesAtLevel(struct Node *ptr, int level)
{
    if(ptr==NULL)
        return 0;
    if(level==0)
        return 1;
    return NodesAtLevel(ptr->left,level-1)+NodesAtLevel(ptr->right,level-1);
}
int main() {

    struct Node* root = NULL;
    struct Node* ptr = NULL;
    int i, num,no,n,level;
    printf("Genearte the set of no's\n");
    scanf("%d",&no);
    printf("The no's are:\n ");
    for (i = 0; i < no; i++)
        {
        num = rand() % 100;
        root = insertNode(root, num);
        printf("%d\n", num);
    }
    FILE* file=fopen("E:\\Rand.txt","r");
    if(file==NULL)
    {
        printf("Failed to open\n");
        return 1;
    }
     for(i=0;i<n;i++)
    {
        fprintf(file, "%d\n",num);
    }
    printf("\nInorder:\n ");
    inorderTraversal(root,file);
    fclose(file);

    printf("\nPreorder:\n");
    preorderTraversal(root,file);
    fclose(file);

    printf("\nPostorder:\n");
    postorderTraversal(root,file);
    fclose(file);

    printf("\nLevel:");
    NodesAtLevel(ptr,level);
    return ;
}

