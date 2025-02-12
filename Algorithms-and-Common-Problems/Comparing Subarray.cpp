// https://atcoder.jp/contests/abc367/tasks/abc367_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand_gen(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r) (rng);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, q; cin >> n >> q;
    ll cmp[n+1];
    for (ll i = 1; i <= n; i++) cmp[i] = rand_gen(1, 1e13);

    ll a[n+1] = {0};
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = a[i-1] + cmp[a[i]];
    }   
    
    ll b[n+1] = {0};
    for (ll i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] = b[i-1] + cmp[b[i]];
    }   

    while (q--) {
        ll l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        cout << (r1-l1 == r2-l2 and a[r1]-a[l1-1] == b[r2]-b[l2-1] ? "Yes\n" : "No\n");
    }
}
