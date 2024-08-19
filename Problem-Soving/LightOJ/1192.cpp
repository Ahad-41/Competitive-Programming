#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        ll n; cin >> n;
        ll arr[n*2];
        for (auto &u : arr) cin >> u;

        ll x = 0;
        for (ll i = 1; i < n*2; i += 2) x ^= (arr[i]-arr[i-1]-1);

        cout << (x ? "Alice\n" : "Bob\n");        
    }
}
