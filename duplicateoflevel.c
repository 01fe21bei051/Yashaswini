#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *insert(struct node *ptr, int ikey);
void display(struct node *ptr, int level);
int NodesAtLevel(struct node *ptr, int level);

int main()
{
    struct node *root = NULL, *ptr;
    int choice, k, item, level,n,i;

    srand(time(NULL)); // Seed the random number generator

    while (1)
    {
        printf("\n");
        printf("1. Insert Tree \n");
        printf("2. Display Tree \n");
        printf("3. Number of Nodes \n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter the set");
            scanf("%d",&n);
            printf("The no's are:");
            for(i=0;i<n;i++)
            {
                scanf("%d",&k);
                 k = rand() % 100;

            }
           // Generate a random number
            printf("\nInserting key: %d\n", k);
            root = insert(root, k);
            break;

        case 2:
            printf("\n");
            display(root, 0);
            printf("\n");
            break;

        case 3:
            printf("\nEnter any level: ");
            scanf("%d", &level);
            printf("\nNumber of nodes at level %d: %d\n", level, NodesAtLevel(root, level));
            break;

        case 4:
            printf("\nInorder traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            printf("\nPreorder traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 6:
            printf("\nPostorder traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 7:
            exit(1);

        default:
            printf("\nWrong choice\n");
        }
    }
    return 0;
}

struct node *insert(struct node *ptr, int ikey)
{
    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = ikey;
        ptr->left = NULL;
        ptr->right = NULL;
    }
    else if (ikey < ptr->data)
        ptr->left = insert(ptr->left, ikey);
    else if (ikey > ptr->data)
        ptr->right = insert(ptr->right, ikey);
    else
        printf("\nDuplicate key\n");
    return (ptr);
}

void display(struct node *ptr, int level)
{
    int i;
    if (ptr == NULL)
        return;
    else
    {
        display(ptr->right, level + 1);
        printf("\n");
        for (i = 0; i < level; i++)
            printf("    ");
        printf("%d", ptr->data);
        display(ptr->left, level + 1);
    }
}

int NodesAtLevel(struct node *ptr, int level)
{
    if (ptr == NULL)
        return 0;
    if (level == 0)
        return 1;
    return NodesAtLevel(ptr->left, level - 1) + NodesAtLevel(ptr->right, level - 1);
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
