//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int v;
    int dist;
} Node;

typedef struct {
    Node heap[MAX];
    int size;
} PriorityQueue;

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(PriorityQueue *pq, int v, int dist) {
    int i = pq->size++;
    pq->heap[i].v = v;
    pq->heap[i].dist = dist;

    while (i != 0 && pq->heap[(i - 1) / 2].dist > pq->heap[i].dist) {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Node pop(PriorityQueue *pq) {
    Node root = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];

    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < pq->size && pq->heap[left].dist < pq->heap[smallest].dist)
            smallest = left;
        if (right < pq->size && pq->heap[right].dist < pq->heap[smallest].dist)
            smallest = right;

        if (smallest != i) {
            swap(&pq->heap[i], &pq->heap[smallest]);
            i = smallest;
        } else break;
    }
    return root;
}

int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

int graph[MAX][MAX], n;

void dijkstra(int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    PriorityQueue pq;
    pq.size = 0;

    dist[src] = 0;
    push(&pq, src, 0);

    while (!isEmpty(&pq)) {
        Node node = pop(&pq);
        int u = node.v;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                push(&pq, v, dist[v]);
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int edges, u, v, w, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(src);

    return 0;
}