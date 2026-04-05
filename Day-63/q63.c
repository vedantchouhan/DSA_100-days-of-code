#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void addEdge(struct Node* adj[], int u, int v) {
    // undirected → both directions
    struct Node* node = newNode(v);
    node->next = adj[u];
    adj[u] = node;

    node = newNode(u);
    node->next = adj[v];
    adj[v] = node;
}

void dfs(struct Node* adj[], int visited[], int src) {
    visited[src] = 1;
    printf("%d ", src);

    struct Node* temp = adj[src];
    while (temp != NULL) {
        if (!visited[temp->data])
            dfs(adj, visited, temp->data);
        temp = temp->next;
    }
}

void freeList(struct Node* adj[], int n) {
    for (int i = 0; i < n; i++) {
        struct Node* temp = adj[i];
        while (temp != NULL) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
}

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Node* adj[n];
    int visited[n];
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int src;
    printf("Enter starting vertex: ");
    scanf("%d", &src);

    printf("\nDFS Traversal: ");
    dfs(adj, visited, src);
    printf("\n");

    freeList(adj, n);
    return 0;
}