#include<stdio.h>
#define MAX_N 20005
int n, parent[MAX_N], Size[MAX_N];

void Initialization() {
    int i;
    for (i = 0; i < MAX_N; i++) {
        parent[i] = i;
        Size[i] = 1;
    }
}

int Find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = Find(parent[v]);
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);

    if (u != v) {
        if (Size[u] < Size[v]) {
            int temp = u;
            u = v;
            v = temp;
        }
        parent[v] = u;
        Size[u] += Size[v];
    }
}

int enemyID(int v) {
    return v+n;
}

int main() {
    scanf("%d", &n);
    Initialization();

    int c, x, y;
    while (scanf("%d %d %d", &c, &x, &y) == 3) {
        if (c == 0 && x == 0 && y == 0) break;

        if (c == 1) {
            if (Find(x) == Find(enemyID(y))) printf("-1\n");
            else {
                Union(x, y);
                Union(enemyID(x), enemyID(y));
            }
        }

        else if (c == 2) {
            if (Find(x) == Find(y)) printf("-1\n");
            else{
                Union(x, enemyID(y));
                Union(enemyID(x), y);
            } 
        }

        else if (c == 3) {
            if (Find(x) == Find(y)) printf("1\n");
            else printf("0\n");
        }

        else {
            if (Find(x) == Find(enemyID(y))) printf("1\n");
            else printf("0\n");
        }
    }

    return 0;
}
