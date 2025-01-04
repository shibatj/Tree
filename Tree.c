#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

void insert(struct Node **root, int data)
{
    if(*root == NULL)
    {
        *root = newNode(data);
        return;
    }

    if(data < (*root)->data)
    {
        insert(&(*root)->left, data);
    }else{
        insert(&(*root)->right, data);
    }
}

void search(struct Node *root)
{
    if(root == NULL) return; //return nothing

    search(root->left);
    printf("%d ", root->data);
    search(root->right);
}

int main()
{
    struct Node *root = NULL;

    int choice = 0;
    int data;

    do{
        scanf("%d", &data);
        insert(&root,data);
        printf("Add More? 1 yes || 0 No >> ");
        scanf("%d", &choice);
    }while(choice != 0);

    printf("Search");
    search(root);
    printf("\n");
}