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

int searchBST(node* root, int key){
    if(root == NULL)
        return 0;

    if(root->data == key)
        return 1;
    else if(key < root->data)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

int main(){
    node* root = NULL;
    int n, val, key;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &val);
        root = insertBST(root, val);
    }

    scanf("%d", &key);

    if(searchBST(root, key))
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}