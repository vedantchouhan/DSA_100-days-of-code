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

// Find index of value in inorder array
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == value) return i;
    return -1;
}

// preStart: current root in preorder
// inStart-inEnd: current subtree's range in inorder
Node* build(int preorder[], int inorder[], int* preIndex, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    // Next element in preorder is always the current root
    int rootVal = preorder[(*preIndex)++];
    Node* root = newNode(rootVal);

    // Find root in inorder → splits left and right subtrees
    int inRoot = findIndex(inorder, inStart, inEnd, rootVal);

    // Left subtree uses inorder[inStart .. inRoot-1]
    root->left  = build(preorder, inorder, preIndex, inStart, inRoot - 1);
    // Right subtree uses inorder[inRoot+1 .. inEnd]
    root->right = build(preorder, inorder, preIndex, inRoot + 1, inEnd);

    return root;
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[100], inorder[100];
    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;
    Node* root = build(preorder, inorder, &preIndex, 0, n - 1);
    postorder(root);

    return 0;
}