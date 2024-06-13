#include <bits/stdc++.h>
using namespace std;

int Parent[10005], Size[10005];

int find(int v) {
    if (Parent[v] == v) return v;
    return Parent[v] = find(Parent[v]);
}

void Union(int u, int v) {
    u = find(u);
    v = find(v);

    if (u != v) {
        if (Size[u] < Size[v]) swap(u, v);
        Parent[v] = u;
        Size[u] += Size[v];
    }
    
}

int main()
{
    int node, edge; cin >> node >> edge;
    for (int i = 1; i <= node; i++) {
        Parent[i] = i;
        Size[i] = 1;
    }

    while (edge--) {
        int u, v; cin >> u >> v;
        Union(u, v);
    }

    int connectedComponent = 0;
    for (int i = 1; i <= node; i++) {
        if (Parent[i] == i) connectedComponent++;
    }

    cout << connectedComponent << endl;
}
