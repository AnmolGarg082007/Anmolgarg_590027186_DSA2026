#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    printf("Enter matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &adj[i][j]);

    int flag = 1;

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(adj[i][j] != adj[j][i]) {
                flag = 0;
                break;
            }
        }
    }

    if(flag)
        printf("Undirected Graph\n");
    else
        printf("Directed Graph\n");

    return 0;
}