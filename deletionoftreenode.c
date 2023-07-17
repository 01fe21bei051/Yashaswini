#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *getNewNode(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert(struct node *root, int val)
{
    if(root == NULL)
        return getNewNode(val);
    if(root->data < val)
        root->right = insert(root->right,val);
    else if(root->data > val)
        root->left = insert(root->left,val);

    return root;
}

int getRightMin(struct node *root)
{
    struct node *temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}

struct node *removeNode(struct node *root, int val)
{
    if(root == NULL)
        return NULL;

    if(root->data < val)
        root->right = removeNode(root->right,val);
    else if(root->data > val)
        root->left = removeNode(root->left,val);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            int rightMin = getRightMin(root->right);
            root->data = rightMin;
            root->right = removeNode(root->right,rightMin);
        }
    }

    return root;
}

void inorder(struct node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main()
{
    struct node *root = NULL;
    int no,num,i;
    printf("Enter the set of no's\n");
    scanf("%d",&no);
    printf("\nThe no's are:\n");
    for(i=0;i<no;i++)
    {
        scanf("%d",&num);//if generating random no's add num = rand() % 100;
        root = insert(root, num);

    }
    printf("Enter the no to be deleted:\n");
    scanf("%d",&num);
    root=removeNode(root,num);
    inorder(root);
    printf("\n");
    return 0;
}

