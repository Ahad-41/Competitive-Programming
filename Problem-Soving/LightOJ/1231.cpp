#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

const ll M = 100000007;
ll a[55], c[55], dp[55][2000];

ll func(ll i, ll k) {
    if (k == 0) return 1;
    if (i <= 0) return 0;

    if (dp[i][k] != -1) return dp[i][k];

    ll ways = 0;
    for (ll j = 0; j <= c[i]; j++) {
        if (k - j*a[i] < 0) break;
        ways = (ways + func(i-1, k - j*a[i])) % M;
    }

    return dp[i][k] = ways; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1; cin >> tt;

    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";
        answer();
    }

    return 0;
}

void answer() {
    ll n, k; cin >> n >> k;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    for (ll i = 1; i <= n; i++) cin >> c[i];

    memset(dp, -1, sizeof(dp));
    cout << func(n, k) << endl;
}
