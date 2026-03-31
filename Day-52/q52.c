#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create node
struct node* createNode(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Build tree from level order
struct node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct node** queue = (struct node**)malloc(n * sizeof(struct node*));
    int front = 0, rear = 0;

    struct node* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct node* curr = queue[front++];

        // Left child
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    free(queue);
    return root;
}

// LCA function
struct node* LCA(struct node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    struct node* left = LCA(root->left, n1, n2);
    struct node* right = LCA(root->right, n1, n2);

    if (left && right)
        return root;

    return (left != NULL) ? left : right;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct node* root = buildTree(arr, n);

    struct node* lca = LCA(root, n1, n2);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}