#include <stdio.h>
#include <stdlib.h>

// ─── stack ────────────────────────────────────────
struct Stack {
    int items[100];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmptyStack(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int val) {
    s->items[++s->top] = val;
}

int pop(struct Stack* s) {
    return s->items[s->top--];
}

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
    // directed → only u → v
    struct Node* node = newNode(v);
    node->next = adj[u];
    adj[u] = node;
}

// ─── DFS + push to stack after visiting all neighbors ─
void dfs(struct Node* adj[], int visited[], struct Stack* s, int src) {
    visited[src] = 1;

    struct Node* temp = adj[src];
    while (temp != NULL) {
        if (!visited[temp->data])
            dfs(adj, visited, s, temp->data);
        temp = temp->next;
    }

    // push AFTER all neighbors done
    push(s, src);
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

    printf("Enter %d directed edges (u v means u→v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    struct Stack s;
    initStack(&s);

    // call DFS for every unvisited node
    // (handles disconnected components too)
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(adj, visited, &s, i);

    // pop stack = topological order
    printf("\nTopological Order: ");
    while (!isEmptyStack(&s))
        printf("%d ", pop(&s));
    printf("\n");

    freeList(adj, n);
    return 0;
}