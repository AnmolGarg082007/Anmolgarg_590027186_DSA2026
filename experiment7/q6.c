#include <stdio.h>

void dfs(int v, int n, int adj[n][n], int visited[]) {
    printf("%d ", v);
    visited[v] = 1;

    for(int i=0;i<n;i++) {
        if(adj[v][i]==1 && !visited[i]) {
            dfs(i, n, adj, visited);
        }
    }
}

int main() {
    int n, i, j, start;
    printf("Enter vertices: ");
    scanf("%d", &n);

    int adj[n][n], visited[n];

    printf("Enter matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &adj[i][j]);

    for(i=0;i<n;i++) visited[i]=0;

    printf("Start vertex: ");
    scanf("%d", &start);

    printf("DFS: ");
    dfs(start, n, adj, visited);

    return 0;
}