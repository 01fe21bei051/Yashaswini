#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
    int ht;
};

struct node* root = NULL;

struct node* create(int);
struct node* insert(struct node*, int);
struct node* delete(struct node*, int);
struct node* search(struct node*, int);
struct node* rotate_left(struct node*);
struct node* rotate_right(struct node*);
int balance_factor(struct node*);
int height(struct node*);
void inorder(struct node*, FILE*);
void preorder(struct node*, FILE*);
void postorder(struct node*, FILE*);
int nodesAtLevel(struct Node *ptr, int );


int main() {
    int ch, data,i,level;
    struct node* result = NULL;
      do
        {

        printf("1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Inorder");
        printf("\n5. Preorder");
        printf("\n6. Postorder");
        printf("\n7.levels:");
        printf("\n8. Exit");
        printf("\nEnter Your Choice: \n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                root = insert(root, data);

                FILE *fp2= fopen("E:\\source.txt","w");
                if (fp2 == NULL)
                    {
                 printf("Error opening file.\n");
                  return 1;
                  }
                 fclose(fp2);
                break;

            case 2:
                printf("\nEnter data: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;

            case 3:
                printf("\nEnter data: ");
                scanf("%d", &data);
                result = search(root, data);
                if (result == NULL) {
                    printf("\nNode not found");
                } else {
                    printf("\n Node found");
                }
                break;

            case 4:
                inorder(root, stdout);
                printf("Inorder traversal: ");
                FILE *fp3= fopen("E:\\in.txt","w");
                if (fp3 == NULL)
                    {
                     printf("Error opening file.\n");
                      return 1;
                    }
                 inorder(root,fp3);
                 fclose(fp3);
                 printf("\nInorder printed\n");
                break;

            case 5:
                preorder(root, stdout);
                printf("\nPreorder traversal: \n");

                FILE *fp5= fopen("E:\\preord.txt","w");
               if (fp5 == NULL)
                {
                printf("Error opening file.\n");
                return 1;
               }
               preorder(root, fp5);
               fclose(fp5);
               printf("\nPreorder printed\n");
                break;

            case 6:
                postorder(root, stdout);
                printf("\nPostorder traversal: \n");
              FILE *fp4= fopen("E:\\post.txt","w");
            if (fp4 == NULL)
                {
             printf("Error opening file.\n");
             return 1;
                 }
              postorder(root,fp4);
              fclose(fp4);
              printf("\nPostorder printed \n");
                break;

            case 7:
            printf("Enter any level : ");
            scanf("%d",&level);
            printf("\nNumber of nodes at %d Level :: %d\n",level,NodesAtLevel(root,level));
            break;

                 case 8:
                exit(0);
                return 1;

            default:
                printf("\nInvalid Choice\n");
        }
    }while(ch!=7);
    printf("Inorder traversal: ");
                FILE *fp3= fopen("E:\\in.txt","w");
                if (fp3 == NULL)
                    {
                     printf("Error opening file.\n");
                      return 1;
                    }
                 inorder(root,fp3);
                 fclose(fp3);
                 printf("\nInorder printed\n");
}

struct node* create(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("\nMemory can't be allocated\n");
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* rotate_left(struct node* root) {
    struct node* right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;
    root->ht = height(root);
    right_child->ht = height(right_child);
    return right_child;
}

struct node* rotate_right(struct node* root) {
    struct node* left_child = root->left;
    root->left = left_child->right;
    left_child->right = root;
    root->ht = height(root);
    left_child->ht = height(left_child);
    return left_child;
}

int balance_factor(struct node* root) {
    int lh, rh;
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    return lh - rh;
}

int height(struct node* root) {
    int lh, rh;
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    if (lh > rh)
        return (lh);
    return (rh);
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        struct node* new_node = create(data);
        if (new_node == NULL) {
            return NULL;
        }
        root = new_node;
    } else if (data > root->data) {
        root->right = insert(root->right, data);
        if (balance_factor(root) == -2) {
            if (data > root->right->data) {
                root = rotate_left(root);
            } else {
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    } else {
        root->left = insert(root->left, data);
        if (balance_factor(root) == 2) {
            if (data < root->left->data) {
                root = rotate_right(root);
            } else {
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    }
    root->ht = height(root);
    return root;
}

struct node* delete(struct node* root, int x) {
    struct node* temp = NULL;

    if (root == NULL) {
        return NULL;
    }

    if (x > root->data) {
        root->right = delete(root->right, x);
        if (balance_factor(root) == 2) {
            if (balance_factor(root->left) >= 0) {
                root = rotate_right(root);
            } else {
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    } else if (x < root->data) {
        root->left = delete(root->left, x);
        if (balance_factor(root) == -2) {
            if (balance_factor(root->right) <= 0) {
                root = rotate_left(root);
            } else {
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    } else {
        if (root->right != NULL) {
            temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
            if (balance_factor(root) == 2) {
                if (balance_factor(root->left) >= 0) {
                    root = rotate_right(root);
                } else {
                    root->left = rotate_left(root->left);
                    root = rotate_right(root);
                }
            }
        } else {
            return (root->left);
        }
    }
    root->ht = height(root);
    return (root);
}

struct node* search(struct node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == key) {
        return root;
    }
    if (key > root->data) {
        return search(root->right, key);
    } else {
        return search(root->left, key);
    }
}

void inorder(struct node* root, FILE* fp) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, fp);
    fprintf(fp, "%d ", root->data);
    inorder(root->right, fp);
}

void preorder(struct node* root, FILE* fp) {
    if (root == NULL) {
        return;
    }
    fprintf(fp, "%d ", root->data);
    preorder(root->left, fp);
    preorder(root->right, fp);
}

void postorder(struct node* root, FILE* fp) {
    if (root == NULL) {
        return;
    }
    postorder(root->left, fp);
    postorder(root->right, fp);
    fprintf(fp, "%d ", root->data);
}
 int nodesAtLevel(struct node* ptr,int level)
{
        if(ptr==NULL)
                return 0;
        if(level==0)
                return 1;
        return nodesAtLevel(ptr->left,level-1) + nodesAtLevel(ptr->right,level-1);
}


