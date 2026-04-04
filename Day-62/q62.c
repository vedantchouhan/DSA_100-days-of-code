#include <stdio.h>
#include <stdlib.h>

// linked list node
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

// add edge to adjacency list
void addEdge(struct Node* adj[], int u, int v, int directed) {
    // u → v
    struct Node* node = newNode(v);
    node->next = adj[u];
    adj[u] = node;

    // if undirected, v → u also
    if (!directed) {
        node = newNode(u);
        node->next = adj[v];
        adj[v] = node;
    }
}

void printList(struct Node* adj[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);
        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// free memory
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

    // array of linked list heads, all NULL initially
    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int directed;
    printf("Directed graph? (1=Yes / 0=No): ");
    scanf("%d", &directed);

    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v, directed);
    }

    printf("\nAdjacency List:\n");
    printList(adj, n);

    freeList(adj, n);
    return 0;
}