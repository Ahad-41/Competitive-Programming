#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e5+7;
vector<ll> adjList[N], revAdjList[N], order;
ll inDegree[N], outDegree[N], cnt, kotoNum[N];
bool vis1[N], vis2[N], vis3[N];

void dfs1(ll currNode) {
    if (vis1[currNode]) return;

    vis1[currNode] = true;
    for (auto &u : adjList[currNode]) dfs1(u);
    order.push_back(currNode);
}

void dfs2(ll currNode) {
    if (vis2[currNode]) return;

    vis2[currNode] = true;
    for (auto &u : revAdjList[currNode]) dfs2(u);
    kotoNum[currNode] = cnt;
}

void dfs3(ll currNode) {
    if (vis3[currNode]) return;
    
    vis3[currNode] = true;
    for (auto &u : adjList[currNode]) {
        if (kotoNum[currNode] != kotoNum[u]) {
            inDegree[kotoNum[u]]++;
            outDegree[kotoNum[currNode]]++;
        }
        dfs3(u);
    }
}

int main()
{
    ll t; cin >> t;
    for (ll j = 1; j <= t; j++) {
        cout << "Case " << j << ": ";

        ll node, edge;
        cin >> node >> edge;

        // ------------------ reset
        for (ll i = 0; i <= node; i++) {
            adjList[i].clear();
            revAdjList[i].clear();
            vis1[i] = vis2[i] = vis3[i] = false;
            inDegree[i] = outDegree[i] = kotoNum[i] = 0;
        }
        order.clear();
        cnt = 0;
        //--------------------------

        while (edge--) {
            ll u, v; cin >> u >> v;
            adjList[u].push_back(v);
            revAdjList[v].push_back(u);
        }

        //------------------- scc
        for (ll i = 1; i <= node; i++) dfs1(i);
        reverse(order.begin(), order.end());

        for (auto &u : order) {
            if (vis2[u]) continue; 
            cnt++;
            dfs2(u);
        }
        //------------------------

        if (cnt == 1) {
            cout << "0\n";
            continue;
        }

        for (ll i = 1; i <= node; i++) {
            if (vis3[i]) continue;
            dfs3(i);
        }

        ll totalInDegree = 0, totalOutDegree = 0;
        for (ll i = 1; i <= cnt; i++) {
            if (inDegree[i] == 0) totalInDegree++;
            if (outDegree[i] == 0) totalOutDegree++;
        }

        cout << max(totalInDegree, totalOutDegree)<< "\n";
    }
}
