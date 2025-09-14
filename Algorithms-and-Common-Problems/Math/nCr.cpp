#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e6+5;
ll fact[N], revFact[N];

const ll M = 1e9+7;
ll bigMod(ll base, ll power) {
    if (!power) return 1;
    ll result = bigMod(base, power/2);
    result = (result * result) % M;
    if (power & 1) result = (result * base) % M;
    return result;
}

// ll nCr(ll n, ll r) {
    // double value = 1;
    // for(ll i = 1; i <= r; i++){
        // value = value * (n - r + i) / i;
    // }
    // return (ll)value;
// }

ll nCr(ll n, ll r) {
    ll upore = fact[n];
    ll niche = (revFact[r] * revFact[n-r]) % M;
    return (upore*niche) % M;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    fact[0] = 1;
    for (ll i = 1; i < N; i++) fact[i] = (fact[i-1]*i) % M;
    
    revFact[N-1] = bigMod(fact[N-1], M-2);
    for (ll i = N-2; i >= 0; i--) revFact[i] = (revFact[i+1]*(i+1)) % M;
    
    ll n, r; cin >> n >> r;
    cout << nCr(n, r);
}
