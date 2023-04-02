#include <stdio.h>
#define MAX_SIZE 100

int graph[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int stack[MAX_SIZE];
int top = -1;

void dfs(int start, int n) {
    printf("%d ", start);
    visited[start] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

void dfs_iterative(int start, int n) {
    stack[++top] = start;
    visited[start] = 1;
    printf("%d ", start);
    while (top >= 0) {
        int node = stack[top--];
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

int main() {
    int n, m, u, v;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // if the graph is undirected
    }

    printf("Depth First Traversal Recursive: ");
    dfs(0, n);
    printf("\n");

    // resetting visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Depth First Traversal Iterative: ");
    dfs_iterative(0, n);
    printf("\n");

    return 0;
}
