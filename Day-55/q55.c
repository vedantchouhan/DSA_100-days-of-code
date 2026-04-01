#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    
    struct Node* root = createNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    int i = 1;
    
    while (front < rear && i < n) {
        struct Node* curr = queue[front++];
        
        if (i < n && arr[i] != -1) {
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
    
    free(queue);
    return root;
}

void rightViewUtil(struct Node* root, int level, int* max_level) {
    if (root == NULL) return;
    
    if (*max_level < level) {
        printf("%d ", root->data);
        *max_level = level;
    }
    
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}

void rightView(struct Node* root) {
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    
    if (n <= 0) {
        return 0;
    }
    
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct Node* root = buildTree(arr, n);
    
    rightView(root);
    
    free(arr);
    return 0;
}