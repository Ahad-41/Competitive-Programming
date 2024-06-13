#include <bits/stdc++.h>
using namespace std;
typedef int ll;

const ll N = 1e5+7;
ll parent[N][20], s[N];

void preCompute(ll n) {
    for (ll i = 1; i <= log2(n); i++) {
        for (ll node = 0; node < n; node++) {
            if (parent[node][i-1] != -1) {
                parent[node][i] = parent[parent[node][i-1]][i-1];
            }
        }
    }
}

int main()
{
    ll t; cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ":" << endl;

        memset(parent, -1, sizeof(parent));
        memset(s, 0, sizeof(s));
        ll n, q; cin >> n >> q;
        s[0] = 1;
        parent[0][0] = 0;

        for (ll i = 1; i < n; i++) {
            ll p; cin >> p >> s[i];
            parent[i][0] = p;
        }

        preCompute(n);

        while (q--) {
            ll k, v; cin >> k >> v;
           
            for (ll i = log2(n); i >= 0; i--) {
                if (s[parent[k][i]] >= v) k = parent[k][i];
            }

            cout << k << endl;
        }
    }
    
}
