#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dist[505][505];
 
void floydWarshall(ll v) { // Here v = number of vertex;
    for (ll k = 1; k <= v; k++) {
        for (ll i = 1; i <= v; i++) {
            for (ll j = 1; j <= v; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) and (dist[k][j] != 1e18 and dist[i][k] != 1e18)) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, q; cin >> n >> m >> q;
 
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) dist[i][j] = 1e18;
    }
    for (ll i = 1; i <= n; i++) dist[i][i] = 0;
    
    while (m--) {
        ll a, b, c; cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }
    floydWarshall(n);
 
    while (q--) {
        ll a, b; cin >> a >> b;
        if (dist[a][b] == 1e18) cout << -1 << endl;
        else cout << dist[a][b] << endl;
    }
 
    return 0;
}
