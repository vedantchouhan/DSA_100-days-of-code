#include <stdio.h>
#include <stdlib.h>

int dfs(int node, int** adj, int* size, int* vis, int* rec) {
    vis[node] = 1;
    rec[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int nei = adj[node][i];

        if (!vis[nei]) {
            if (dfs(nei, adj, size, vis, rec))
                return 1;
        } else if (rec[nei]) {
            return 1;
        }
    }

    rec[node] = 0;
    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int** adj = (int**)malloc(V * sizeof(int*));
    int* size = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++)
        adj[i] = (int*)malloc(V * sizeof(int));

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][size[u]++] = v;
    }

    int* vis = (int*)calloc(V, sizeof(int));
    int* rec = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, size, vis, rec)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}