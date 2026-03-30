#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} node;

node* createNode(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

node* insertBST(node* root, int data){
    if(root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insertBST(root->left, data);
    else if(data > root->data)
        root->right = insertBST(root->right, data);

    return root;
}

void inorder(node* root){
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    node* root = NULL;
    int n, val;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &val);
        root = insertBST(root, val);
    }

    inorder(root);
    printf("\n");

    return 0;
}