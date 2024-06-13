// May be I won't be a good programmer, but I will be a good human being.
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()

vector<ll> v;
ll dp[12][2][2][12];

ll func(ll i, ll isSmall, ll isStart, ll howMany) {
    if (i == v.size()) return howMany;
    if (dp[i][isSmall][isStart][howMany] != -1) return dp[i][isSmall][isStart][howMany];

    ll ans = 0, x = 0, y = 0, z = 0, limit = v[i]; 
    if (isSmall) limit = 9;

    if (isStart == 0) {
        for (ll j = 0; j <= limit; j++) x += func(i+1, isSmall | j < v[i], 0, howMany + (j == 0));
    }
    else {
        for (ll j = 1; j <= limit; j++) y += func(i+1, isSmall | j < v[i], 0, howMany);
        z += func(i+1, 1, 1, 0);
    }

    ans = x + y + z;
    return dp[i][isSmall][isStart][howMany] = ans;
}

ll zeroFromOne(ll n) {
    v.clear();
    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    reverse(all(v));

    memset(dp, -1, sizeof(dp));
    ll zero = func(0, 0, 1, 0);
    if (n != -1) zero++;

    return zero;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ": ";
        ll x, y; cin >> x >> y;
        cout << zeroFromOne(y) - zeroFromOne(x-1) << "\n";
    }

    return 0;
}
