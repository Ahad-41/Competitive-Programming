#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll M = 1e9+7;
const ll N = 1e6+5;
ll dp[N];

ll derangement(ll n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (dp[n] != -1) return dp[n];
    ll ans = (derangement(n-1) + derangement(n-2)) % M;
    ans = ((n-1) * ans) % M;
    return dp[n] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << derangement(n) << endl;

    return 0;
}
