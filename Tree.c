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
    struct Node *node = (struct Node *)malloc(sizeof(struct Node)); // jorng mem
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

void insert(struct Node **root, int data)
{
    if(*root == NULL) // if we have nothing 
    {
        *root = newNode(data); // create new node
        return; // recursive
    }

    if(data < (*root)->data)
    {
        insert(&(*root)->left, data); //add node at left side if data < root
    }else{
        insert(&(*root)->right, data); //add node at right side if data > root
    }
}

void search(struct Node *root)
{
    if(root == NULL) return; //return nothing

    search(root->left); // search left
    printf("%d ", root->data); // show data in current node
    search(root->right); // search right
}

int main()
{
    struct Node *root = NULL;

    int choice = 0;
    int data;

    do{ // loop get data
        scanf("%d", &data);
        insert(&root,data);
        printf("Add More? 1 yes || 0 No >> ");
        scanf("%d", &choice);
    }while(choice != 0);

    printf("Search");
    search(root);
    printf("\n");
}