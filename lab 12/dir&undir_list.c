#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Vertex {
    struct Node* head;
};

struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Vertex* graph, int src, int dest, int isDirected) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph[src].head;
    graph[src].head = newNode;

    // For undirected graph, add an edge from dest to src as well
    if (!isDirected) {
        newNode = createNode(src);
        newNode->next = graph[dest].head;
        graph[dest].head = newNode;
    }
}

void printGraph(struct Vertex* graph, int vertices) {
    printf("Adjacency List:\n");
    for (int i = 0; i < vertices; ++i) {
        struct Node* current = graph[i].head;
        printf("Vertex %d: ", i);
        while (current != NULL) {
            printf("%d -> ", current->dest);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int vertices, edges, src, dest, isDirected;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Vertex* graph = (struct Vertex*)malloc(vertices * sizeof(struct Vertex));
    for (int i = 0; i < vertices; ++i) {
        graph[i].head = NULL;
    }

    printf("Is the graph directed? (1 for directed, 0 for undirected): ");
    scanf("%d", &isDirected);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; ++i) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest, isDirected);
    }

    printGraph(graph, vertices);

    return 0;
}
