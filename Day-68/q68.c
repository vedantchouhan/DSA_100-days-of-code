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

void addEdge(struct Node* adj[], int indegree[], int u, int v) {
    struct Node* node = newNode(v);
    node->next = adj[u];
    adj[u] = node;
    indegree[v]++;   // v has one more incoming edge
}

// ─── queue (array based) ──────────────────────────
struct Queue {
    int items[100];
    int front, rear;
};

void initQueue(struct Queue* q) { q->front = q->rear = -1; }
int  isEmpty  (struct Queue* q) { return q->front == -1;   }

void enqueue(struct Queue* q, int val) {
    if (isEmpty(q)) q->front = 0;
    q->items[++q->rear] = val;
}

int dequeue(struct Queue* q) {
    int val = q->items[q->front];
    if (q->front == q->rear) initQueue(q);
    else q->front++;
    return val;
}

// ─── Kahn's Algorithm ─────────────────────────────
void topologicalSort(struct Node* adj[], int indegree[], int n) {
    struct Queue q;
    initQueue(&q);

    // step 1: enqueue all vertices with indegree 0
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            enqueue(&q, i);

    int count = 0;          // tracks how many vertices processed
    int topo[100];          // stores topological order
    int idx = 0;

    // step 2: BFS
    while (!isEmpty(&q)) {
        int curr = dequeue(&q);
        topo[idx++] = curr;
        count++;

        // reduce indegree of all neighbors
        struct Node* temp = adj[curr];
        while (temp != NULL) {
            indegree[temp->data]--;
            // if indegree becomes 0 → ready to process
            if (indegree[temp->data] == 0)
                enqueue(&q, temp->data);
            temp = temp->next;
        }
    }

    // step 3: cycle detection
    if (count != n) {
        printf("Cycle detected! Topological sort not possible.\n");
        return;
    }

    printf("Topological Order: ");
    for (int i = 0; i < idx; i++)
        printf("%d ", topo[i]);
    printf("\n");
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
    printf("Enter number of edges (directed): ");
    scanf("%d", &m);

    struct Node* adj[n];
    int indegree[n];
    for (int i = 0; i < n; i++) {
        adj[i]      = NULL;
        indegree[i] = 0;
    }

    printf("Enter %d edges (u v) meaning u→v:\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, indegree, u, v);
    }

    topologicalSort(adj, indegree, n);

    freeList(adj, n);
    return 0;
}