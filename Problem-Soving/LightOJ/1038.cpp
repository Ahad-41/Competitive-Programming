// From Bangladesh 2.0
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5+7;
bool visited[N];
double dp[N];

double func(ll n) {
    if (n == 1) return 0;
    if (visited[n]) return dp[n];
    visited[n] = true;

    double ans = 0;
    ll divisor = 0;
    for (ll i = 1; i*i <= n; i++) {
        if (n % i) continue;
        ans += func(i);
        divisor++;

        if (i*i != n) {
            ans += func(n/i);
            divisor++;
        }
    }

    ans += divisor;
    ans /= (divisor-1);
    return dp[n] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        ll n; cin >> n;
        cout << fixed << setprecision(6) << func(n) << "\n";
    }
}
