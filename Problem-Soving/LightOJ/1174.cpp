#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vi;
void answer();

vi adjList[105];
ll n, r;

vi bfs(ll rootNode) {
    vi distance(n);
    bool visited[n] = {false};
    queue <ll> q;
    q.push(rootNode);
    visited[rootNode] = true;

    while (!q.empty()) {
        ll currNode = q.front();
        q.pop();

        for (auto &u : adjList[currNode]) {
            if (visited[u] == false) {
                q.push(u);
                visited[u] = true;
                distance[u] = distance[currNode] + 1;
            }
        }
    }

    return distance;
}

int main()
{
    ll t; cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        answer();
    }
}

void answer() {
    cin >> n >> r;
    for (ll i = 0; i < n; i++) adjList[i].clear();

    for (ll i = 1; i <= r; i++) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    ll s, d; cin >> s >> d;
    vi first = bfs(s);
    vi second = bfs(d);

    ll ans = 0;
    for (ll i = 0; i < n; i++) ans = max(ans, first[i]+second[i]);

    cout << ans << endl;
}
