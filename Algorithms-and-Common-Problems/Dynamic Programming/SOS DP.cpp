// https://codeforces.com/contest/165/problem/E

#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 22)+5;
int dp[N];

signed main()
{
    int n; cin >> n;

    for (int i = 0; i < N; i++) dp[i] = -1;
    int arr[n];
    for (auto &u : arr) {
        cin >> u;
        dp[u] = u;
    }

    for (int mask = 0; mask < N; mask++) {
        for (int i = 0; i < 22; i++) {
            if (mask & (1 << i)) 
                dp[mask] = max(dp[mask], dp[(mask ^ (1<<i))]);
        }
    }

    for (auto &u : arr) {
        cout << dp[((1 << 22) - 1) ^ u] << " ";
    }   
}

// ------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = (1 << 10);
ll cnt[N], dp[N][10];

ll func(ll mask, ll i) {
    if (i < 0) return (cnt[mask] ? mask : -1);
    if (dp[mask][i] != -2) return dp[mask][i];

    ll ans;
    if ((mask & (1 << i))) {
        ans = func(mask, i-1);
        ans = max(ans, func((mask ^ (1 << i)), i-1));
    }
    else ans = func(mask, i-1);

    return dp[mask][i] = ans;
}

signed main()
{
    ll n; cin >> n;
    ll arr[n];
    for (auto &u : arr) {
        cin >> u;
        cnt[u]++;
    }

    for (ll i = 0; i < N; i++) for (ll j = 0; j < 10; j++) dp[i][j] = -2;
    for (auto &u : arr) {
        ll temp = ((N-1) ^ u); // reverse every bit
        cout << func(temp, 9) << " ";
    }   
}
