// May be I won't be a good programmer, but I will be a good human being.
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll M = 1e9+7;
const ll N = 2e6+7;
ll fact[N], invFact[N];

ll bigMod(ll base, ll power) {
    if (!power) return 1; // base case
    ll result = bigMod(base, power/2);
    result = (result * result) % M;
    if (power & 1) result = (result * base) % M;
    return result;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    fact[0] = 1;
    for (ll i = 1; i < N; i++) fact[i] = (fact[i-1] * i) % M;

    invFact[N-1] = bigMod(fact[N-1], M-2);
    for (ll i = N-2; i >= 0; i--) invFact[i] = (invFact[i+1] * (i+1)) % M;

    ll tt = 1; cin >> tt;
    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ": ";
        ll n, k; cin >> n >> k;
        // (n+k-1)C(k-1)
        // fact(n+k-1) / (fact(k-1) * fact((n+k-1)-(k-1)));
        cout << (((fact[n+k-1] * invFact[k-1]) % M) * invFact[n]) % M << "\n";
    }

    return 0;
}
