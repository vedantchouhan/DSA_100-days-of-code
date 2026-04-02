#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order input
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = newNode(arr[0]);
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (front < rear && i < n) {
        Node* curr = queue[front++];

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

// Mirror: swap left and right at every node
void mirror(Node* root) {
    if (root == NULL) return;

    // Swap children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recurse
    mirror(root->left);
    mirror(root->right);
}

// Inorder: Left → Root → Right
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);
    mirror(root);
    inorder(root);

    return 0;
}
