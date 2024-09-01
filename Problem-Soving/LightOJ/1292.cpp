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

        pair<ll, ll> v[n];
        for (auto &u : v) cin >> u.first >> u.second;

        ll mx = 0;

        for (ll i = 0; i < n-1; i++) {
            map<pair<ll, ll>, ll> cnt;
            for (ll j = i+1; j < n; j++) {
                ll x = v[i].first-v[j].first;
                ll y = v[i].second-v[j].second;

                ll gcd = __gcd(x, y);
                x /= gcd;
                y /= gcd;
                cnt[{x, y}]++;
            }
            for (auto &u : cnt) mx = max(mx, u.second);
            
        }       

        cout << mx+1 << "\n";
    }
}
