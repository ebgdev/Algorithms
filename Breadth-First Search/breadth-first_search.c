#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100 // maximum size of queue

int adj_matrix[10][10]; // adjacency matrix to represent graph
int visited[10]; // to mark visited nodes
int queue[MAX_QUEUE_SIZE]; // to store nodes to be processed
int front = -1, rear = -1; // front and rear of queue

void enqueue(int node) {
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue overflow!\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = node;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow!\n");
        return -1;
    }
    int node = queue[front];
    front++;
    return node;
}

void bfs(int start, int n) {
    visited[start] = 1;
    enqueue(start);
    while (front != -1) {
        int current = dequeue();
        printf("%d ", current);
        for (int i = 0; i < n; i++) {
            if (adj_matrix[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int n, start;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
    printf("Enter the starting node for BFS: ");
    scanf("%d", &start);
    printf("BFS traversal starting from node %d: ", start);
    bfs(start, n);
    printf("\n");
    return 0;
}
