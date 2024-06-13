#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll M = 10056;
const ll N = 1005;
ll dp[N];
vector<ll> pascal[N];

ll func(ll n) {
    if (n == 0) return 1;
    if (dp[n] != -1) return dp[n];
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ll temp = (func(i) * pascal[n][n-i]) % M;
        ans = (ans + temp) % M;
    }
    return dp[n] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    pascal[0].push_back(1);
    for (ll i = 1; i <= 1000; i++) {
        pascal[i].push_back(1);
        for(ll j = 0; j < pascal[i-1].size()-1; j++) {
            pascal[i].push_back((pascal[i-1][j] + pascal[i-1][j+1]) % M);
        }
        pascal[i].push_back(1);
    }

    memset(dp, -1, sizeof(dp));
    func(1000);

    ll tt = 1; cin >> tt;
    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";
        ll n; cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}
