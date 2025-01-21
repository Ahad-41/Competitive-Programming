// https://cses.fi/problemset/task/1750
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, q; cin >> n >> q;

    ll sparseTable[32][n+1];
    memset(sparseTable, -1, sizeof(sparseTable));
    for (ll i = 1; i <= n; i++) cin >> sparseTable[0][i];

    for (ll i = 1; i <= 31; i++) {
        for (ll j = 1; j <= n; j++) {
            sparseTable[i][j] = sparseTable[i-1][sparseTable[i-1][j]];
        }
    }

    while (q--) {
        ll x, k; cin >> x >> k;
        
        ll ans = x;
        bitset<32> b(k);
        for (ll i = 0; i <= 31; i++) {
            if (b[i]) ans = sparseTable[i][ans];
        }

        cout << ans << "\n";
    }
}
