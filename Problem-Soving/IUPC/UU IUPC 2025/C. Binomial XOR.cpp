#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M = 998244353;
const ll N = 1e6+7;
ll ans[N], fact[N], invFact[N];

ll bigMod(ll a, ll b) {
    if (!b) return 1;
    ll ans = bigMod(a, b/2);
    ans = (ans*ans) % M;
    if (b & 1) ans = (ans * a) % M;
    return ans;
}

ll nCr(ll n, ll r) {
    return (((fact[n] * invFact[n - r]) % M) * invFact[r]) % M;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tt = 1; cin >> tt;

    fact[0] = 1;
    for (ll i = 1; i < N; i++) fact[i] = (fact[i-1] * i) % M;
    
    invFact[N-1] = bigMod(fact[N-1], M-2);
    for (ll i = N-2; i >= 0; i--) invFact[i] = (invFact[i+1] * (i+1)) % M;

    for (ll i = 1; i <= 1000000; i++) {
        ans[i] ^= ans[i-1];
        if (i % 2 == 0) ans[i] ^= nCr(i, i/2);
    }

    test:
    while (tt--) {
        ll n; cin >> n;
        ll res = 0;
        if (n & 1) res = 1;
        cout << (ans[n] ^ res) << "\n";
    }
}
