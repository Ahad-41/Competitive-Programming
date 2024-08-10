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
        map<ll, vector<string>> cnt; 
        for (ll i = 1; i <= n; i++) {
            string  s; cin >> s;
            ll a, b, c; cin >> a >> b >> c;
            cnt[a*b*c].push_back(s);
        }       

        if (cnt.size() == 1) {
            cout  << "no thief\n";
            continue;
        }

        ll a = 0, b = 1e9;
        for (auto &u : cnt) {
            a = max(a, u.first);
            b = min(b, u.first);
        }

        cout << cnt[a][0] << " took chocolate from " <<  cnt[b][0] << "\n";
    }
}
