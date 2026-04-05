#include <stdio.h>
#include <stdlib.h>

// ─── adjacency list ───────────────────────────────
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
    struct Node* node = newNode(v);
    node->next = adj[u];
    adj[u] = node;

    node = newNode(u);
    node->next = adj[v];
    adj[v] = node;
}

// ─── queue (array based) ──────────────────────────
struct Queue {
    int items[100];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear  = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int val) {
    if (q->rear == 99) return;  // queue full
    if (isEmpty(q)) q->front = 0;
    q->items[++q->rear] = val;
}

int dequeue(struct Queue* q) {
    int val = q->items[q->front];
    if (q->front == q->rear)
        initQueue(q);   // queue empty after this
    else
        q->front++;
    return val;
}

// ─── BFS ──────────────────────────────────────────
void bfs(struct Node* adj[], int visited[], int n, int src) {
    struct Queue q;
    initQueue(&q);

    visited[src] = 1;
    enqueue(&q, src);

    while (!isEmpty(&q)) {
        int curr = dequeue(&q);
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;  // mark BEFORE enqueue
                enqueue(&q, temp->data);  // to avoid duplicates
            }
            temp = temp->next;
        }
    }
}

// ─── free memory ──────────────────────────────────
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

// ─── main ─────────────────────────────────────────
int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Node* adj[n];
    int visited[n];
    for (int i = 0; i < n; i++) {
        adj[i]     = NULL;
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

    printf("\nBFS Traversal: ");
    bfs(adj, visited, n, src);
    printf("\n");

    freeList(adj, n);
    return 0;
}