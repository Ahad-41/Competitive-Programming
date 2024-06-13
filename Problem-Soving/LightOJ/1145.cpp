// May be I won't be a good programmer, but I will be a good human being.
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

const ll M = 1e8+7;
ll dp[15005], csum[15005];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ": ";
        answer();
    }

    return 0;
}

void answer() {
    ll n, k, s; cin >> n >> k >> s;

    for (ll i = 1; i <= s; i++) dp[i] = 0;
    dp[0] = 1;

    for (ll i = 0; i < n; i++) {
        csum[0] = dp[0];
        for (ll j = 1; j <= s; j++) csum[j] = csum[j-1] + dp[j];

        for (ll j = 0; j <= s; j++) {
            if (j-k-1 >= 0) dp[j] = (csum[j-1] - csum[j-k-1]) % M;
            else dp[j] = csum[j-1] % M;
        } 
    }

    cout << dp[s] % M << "\n";
}
