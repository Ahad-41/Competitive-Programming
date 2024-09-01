// It's known that the diagonals of a parallelogram split each other in the middle. Let's iterate over the pairs of points a, b and consider the middle of the segment.
// Let's calculate the value cntc for each middle. cntc is the number of segments a, b with the middle c.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    while (tc--) {
        cout << "Case " << tt++ << ": ";
        ll n; cin >> n;
        Pair arr[n];
        for (auto &u : arr) cin >> u.first >> u.second;

        vector<Pair> v;
        for (ll i = 0; i < n-1; i++) {
            for (ll j = i+1; j < n; j++) {
                ll dx = arr[i].first + arr[j].first;
                ll dy = arr[i].second + arr[j].second;
                v.push_back({dx, dy});
            }
        }

        sort(v.begin(), v.end());

        ll ans = 0, cnt = 1;
        for (ll i = 1; i < v.size(); i++) {
            if (v[i] == v[i-1]) cnt++;
            else {
                ans += (cnt) * (cnt-1) / 2;
                cnt = 1;
            }
        }

        cout << ans << "\n";
    }   
}
