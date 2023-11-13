// Write a C program to represent directed and undirected graphs using adjacency
// matrix
#include <stdio.h>

#define max 100

int adja[max][max];
int num;

void initialise(int vertices) {
    num = vertices;

    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            adja[i][j] = 0;
        }
    }
}

void addEdge(int start, int end, int isDirected) {
    if (start >= 0 && start < num && end >= 0 && end < num) {
        // For directed graph
        if (isDirected) {
            adja[start][end] = 1;
        }
        // For undirected graph
        else {
            adja[start][end] = 1;
            adja[end][start] = 1;
        }
    } else {
        printf("Invalid vertices\n");
    }
}

void graph() {
    printf("Adjacency Matrix:\n");

    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            printf("%d ", adja[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, start, end, isDirected;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initialise(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Is the graph directed? (1 for directed, 0 for undirected): ");
    scanf("%d", &isDirected);

    for (int i = 0; i < edges; ++i) {
        printf("Enter edge (start end): ");
        scanf("%d %d", &start, &end);

        addEdge(start, end, isDirected);
    }

    graph();

    return 0;
}
