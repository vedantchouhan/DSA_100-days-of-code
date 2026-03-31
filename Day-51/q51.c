#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create new node
struct node* createNode(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Insert into BST
struct node* insert(struct node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA
struct node* LCA(struct node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);

    if (n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);

    return root; // split point = LCA
}

int main() {
    int n, val, n1, n2;
    struct node* root = NULL;

    // Input
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    scanf("%d %d", &n1, &n2);

    struct node* lca = LCA(root, n1, n2);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}