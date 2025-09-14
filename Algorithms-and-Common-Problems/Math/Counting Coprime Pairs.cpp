#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e6+7;
ll cnt[N], f[N], mobb[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;

    ll arr[n];
    for (auto &u: arr) {
        cin >> u;
        cnt[u]++;
    } 
    
    cnt[1] = n;
    for (ll i = 2; i < N; i++) for (ll j = i*2; j < N; j += i) cnt[i] += cnt[j];
    for (ll i = 1; i < N; i++) f[i] = cnt[i] * (cnt[i]-1) / 2;

    // -----------------------------------------------------------------------------
    // Using Mobius Number
    mobb[1] = 1;
    for (ll i = 1; i < N; i++) for (ll j = i*2; j < N; j += i) mobb[j] -= mobb[i];
    
    ll ans = 0;
    for (ll i = 1; i < N; i++) ans += f[i] * mobb[i];
    cout << ans; 

    /// -----------------------------------------------------------------------------
    // Using Inclusion Exclusion DP
    for (ll i = N; i >= 1; i--) for (ll j = i*2; j < N; j += i) f[i] -= f[j];
    // cout << f[1];
}
