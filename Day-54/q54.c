#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree
struct node* build(int arr[], int n) {
    if (n == 0) return NULL;

    struct node* q[MAX];
    int f = 0, r = 0;

    struct node* root = newNode(arr[0]);
    q[r++] = root;

    int i = 1;
    while (i < n) {
        struct node* cur = q[f++];

        if (arr[i] != -1) {
            cur->left = newNode(arr[i]);
            q[r++] = cur->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            cur->right = newNode(arr[i]);
            q[r++] = cur->right;
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzag(struct node* root) {
    if (!root) return;

    struct node* q[MAX];
    int f = 0, r = 0;

    q[r++] = root;
    int dir = 1;

    while (f < r) {
        int size = r - f;
        int temp[MAX];

        for (int i = 0; i < size; i++) {
            struct node* cur = q[f++];

            int idx = dir ? i : (size - 1 - i);
            temp[idx] = cur->data;

            if (cur->left) q[r++] = cur->left;
            if (cur->right) q[r++] = cur->right;
        }

        for (int i = 0; i < size; i++)
            printf("%d ", temp[i]);

        dir = !dir;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = build(arr, n);
    zigzag(root);

    return 0;
}