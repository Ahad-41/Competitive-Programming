#include <bits/stdc++.h>
using namespace std;
#define Pair pair<int, int> 

const int N = 1e5 + 7;
vector<pair<int, int>> adjList[N];
bool alreadyTaken[N];
int node, edge;

int mst(int currNode) {
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.push({0, currNode});
    int minCost = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        currNode = pq.top().second;
        pq.pop();
        if (alreadyTaken[currNode] == true) continue;
        
        minCost += cost;
        alreadyTaken[currNode] = true;
        
        for (auto &u : adjList[currNode]) {
            if (alreadyTaken[u.first] == false) {
                pq.push({u.second, u.first});
            }
        }         
    } 

    return minCost;
}

int main()
{
    cin >> node >> edge;
    while (edge--) {
        int u, v, w; cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    cout << mst(1) << endl;
}
