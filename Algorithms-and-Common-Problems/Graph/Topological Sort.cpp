#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adjList[N], topSortArray;
int inDegree[N], node, edge;

void topSort() {
    queue <int> q;
    
    for (int i = 0; i < node; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        topSortArray.push_back(currNode);

        for (auto &u : adjList[currNode]) {
            inDegree[u]--;
            if (inDegree[u] == 0) q.push(u); 
        }
    }
}

int main()
{
    cin >> node >> edge;
    while (edge--) {
        int u, v; cin >> u >> v;
        adjList[u].push_back(v);
        inDegree[v]++;
    }

    topSort();

    for (auto &u : topSortArray) cout << u << " ";
    cout << endl;
}