#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
map<string, vector<string>> adjList;
vector<string> topSortArray;

map<string, int> inDegree;
unordered_set<string> s;

void topSort() {
    queue <string> q;
    for (auto &u : s) if (inDegree[u] == 0) q.push(u);
    
    while (!q.empty()) {
        string currNode = q.front();
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
    int tt; cin >> tt;
    for (int t = 1; t <= tt; t++) {
        s.clear();
        adjList.clear();
        topSortArray.clear();
        inDegree.clear();

        int node; cin >> node;
        for (int i = 1; i <= node; i++) {
            string u, v; cin >> u >> v;
            adjList[u].push_back(v);
            inDegree[v]++;
            s.insert(u);
            s.insert(v);
        }

        topSort();
        cout << "Case " << t << ": ";
        cout << (topSortArray.size() == s.size() ? "Yes" : "No") << endl; 
    }
}
