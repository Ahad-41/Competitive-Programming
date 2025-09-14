#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7;
ll Parent[N], Size[N];

ll find(ll v) {
    if (Parent[v] == v) return v;
    return Parent[v] = find(Parent[v]);
}

void Union(ll u, ll v) {
    u = find(u);
    v = find(v);

    if (u != v) {
        if (Size[u] < Size[v]) swap(u, v);
        Parent[v] = u;
        Size[u] += Size[v];
    }
    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;

    for (ll i = 1; i <= n; i++) {
        Parent[i] = i;
        Size[i] = 1;
    }

    while (m--) {
        ll u, v; cin >> u >> v;
        Union(u, v);
    }

    ll connectedComponent = 0;
    for (ll i = 1; i <= n; i++) if (Parent[i] == i) connectedComponent++;
    cout << connectedComponent;
}
