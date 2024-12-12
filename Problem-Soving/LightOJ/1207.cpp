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

        vector<pair<ll, ll>> v;
        set<ll> distinct;
        while (n--) {
            ll l, r; cin >> l >> r;
            v.push_back({l, r});
            distinct.insert(l);
            distinct.insert(r);
        }
        reverse(v.begin(), v.end());
        
        ll index = 1;
        set<ll> s;
        map<ll, ll> mp;
        for (auto &u : distinct) {
            s.insert(index);
            mp[u] = index;
            index++;
        }

        ll ans = 0;
        s.insert(200005);

        for (auto &u : v) {
            auto it1 = s.lower_bound(mp[u.first]);
            auto it2 = s.upper_bound(mp[u.second]);
            
            if (it1 != it2) {
                ans++;
                s.erase(it1, it2);
            }
        }

        cout << ans << "\n";
    }
}
