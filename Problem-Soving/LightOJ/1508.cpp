#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

const ll N = 1e4+5;
vector<ll> adjList[N];
ll n, k, leftBike, bike[N], totalBike[N], subTree[N], visited[N];
multiset<Pair> graph[N];
vector<Pair> ways;

void dfs1(ll currNode) {
    visited[currNode] = 1;

    for (auto &u : adjList[currNode]) {
        if (visited[u]) continue;
        dfs1(u);
        totalBike[currNode] += totalBike[u];
        subTree[currNode] += subTree[u];
        graph[currNode].insert({k*subTree[u]-totalBike[u], u});
    }
    totalBike[currNode] += bike[currNode];
    subTree[currNode]++;
}

void dfs2(ll currNode) {
    visited[currNode] = 1;

    for (auto &u : graph[currNode]) {
        if (visited[u.second] == 1) continue;
        ways.push_back({currNode, -bike[currNode]});
        leftBike += bike[currNode];
        bike[currNode] = 0;
        dfs2(u.second);
    }
    ways.push_back({currNode, k-bike[currNode]});
    leftBike -= bike[currNode];
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ": YES\n";
        answer();
    }

    return 0;
}

void answer() {
    cin >> n >> k;
    
    ways.clear();
    for (ll i = 1; i <= n; i++) {
        adjList[i].clear();
        graph[i].clear();
        bike[i] = visited[i] = subTree[i] = totalBike[i] = 0;
    }

    for (ll i = 1; i < n; i++) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (ll i = 1; i <= n; i++) cin >> bike[i];
    dfs1(1);

    for (ll i = 1; i <= n; i++) visited[i] = 0;
    leftBike = 0;
    dfs2(1);
        
    for (auto &u : ways) cout << u.first << " " << u.second << "\n";
}
