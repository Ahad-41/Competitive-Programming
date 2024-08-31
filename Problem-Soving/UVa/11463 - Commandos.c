#include <stdio.h>
const int Infinity = 100000;
int dist[105][105];

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

void floydWarshall(int v) {
    int i, j, k;
    for (k = 1; k <= v; k++) {
        for (i = 1; i <= v; i++) {
            for (j = 1; j <= v; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != Infinity && dist[i][k] != Infinity)) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    int i, j, curr = 1;
    while (testcase--) {
        int buildings, roads;
        scanf("%d %d", &buildings, &roads); 

        for (i = 1; i <= buildings; i++) {
            for (j = 1; j <= buildings; j++) dist[i][j] = Infinity;
        }
        for (i = 1; i <= buildings; i++) dist[i][i] = 0;

        while (roads--) {
            int u, v;
            scanf("%d %d", &u, &v);
            u++; v++;
            dist[u][v] = dist[v][u] = 1;
        }
        floydWarshall(buildings);

        int s, d;
        scanf("%d %d", &s, &d);
        s++; d++;

        int ans = 0;
        for (i = 1; i <= buildings; i++) {
            if (dist[s][i] == Infinity || dist[i][d] == Infinity) continue;
            if (ans < dist[s][i] + dist[i][d]) {
                ans = dist[s][i] + dist[i][d];
            }
        }

        printf("Case %d: %d\n", curr++, ans);
    }
}
