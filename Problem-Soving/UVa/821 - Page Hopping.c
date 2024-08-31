#include <stdio.h>
const int Infinity = 100000;
int dist[105][105], check[105];

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
    int curr = 1, i, j;
    while (1) {
        for (i = 1; i <= 100; i++) {
            for (j = 1; j <= 100; j++) dist[i][j] = Infinity;
        }
        for (i = 1; i <= 100; i++) {
            dist[i][i] = 0;
            check[i] = 0;
        }

        int u, v;
        scanf("%d %d", &u, &v);
        if (u == 0 && v == 0) break;

        while (1) {
            check[u] = check[v] = 1;
            dist[u][v] = 1;
            scanf("%d %d", &u, &v);
            if (u == 0 && v == 0) break;
        }

        floydWarshall(100);

        double sum = 0, cnt = 0;
		for (i = 1; i <= 100; i++) {
			for (j = 1; j <= 100; j++) {
				if (i == j || check[i] == 0 || check[j] == 0) continue;
				
				sum += dist[i][j];
				cnt++;
			}
		}

		printf("Case %d: average length between pages = %.3lf clicks\n", curr++, sum/cnt);
    }
}
