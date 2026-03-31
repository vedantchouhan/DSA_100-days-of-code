#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Build tree
struct node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct node* queue[MAX];
    int front = 0, rear = 0;

    struct node* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Queue node with horizontal distance
struct QNode {
    struct node* node;
    int hd;
};

// Vertical Order
void verticalOrder(struct node* root) {
    struct QNode queue[MAX];
    int front = 0, rear = 0;

    int map[200][MAX];
    int count[200] = {0};
    int offset = 100;

    queue[rear++] = (struct QNode){root, 0};

    while (front < rear) {
        struct QNode temp = queue[front++];
        int hd = temp.hd + offset;

        map[hd][count[hd]++] = temp.node->data;

        if (temp.node->left)
            queue[rear++] = (struct QNode){temp.node->left, temp.hd - 1};

        if (temp.node->right)
            queue[rear++] = (struct QNode){temp.node->right, temp.hd + 1};
    }

    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}