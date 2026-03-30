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

int countLeafNodes(node* root){
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main(){
    node *root = NULL;

    // Example tree
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int leafCount = countLeafNodes(root);
    printf("%d\n", leafCount);

    return 0;
}