#include <stdio.h>

void dfs(int a[20][20], int n, int source) {
    int visited[10], u, v, i;
    int S[20], top = -1;

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    S[++top] = source;
    visited[source] = 1;

    printf("Depth-First Search starting from vertex %d: ", source);

    while (top >= 0) {
        u = S[top--];

        for (v = 1; v <= n; v++) {
            if (a[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                S[++top] = v;
            }
        }

        printf("%d ", u);
    }
}

int main() {
    int n, a[20][20], source;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dfs(a, n, source);

    return 0;
}
