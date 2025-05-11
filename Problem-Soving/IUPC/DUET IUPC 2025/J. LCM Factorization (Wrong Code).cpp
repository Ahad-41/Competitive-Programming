#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M = 998244353;
const ll N = 3e5+7;
ll spf[N], fact[N], invFact[N];
bool check[N];

ll bigMod(ll base, ll power) {
    if (!power) return 1;
    ll result = bigMod(base, power/2);
    result = (result*result) % M;
    if (power & 1) result = (result*base) % M;
    return result;
}

void sieve() {
    for (ll i = 2; i < N; i += 2) spf[i] = 2;
    for (ll i = 3; i < N; i += 2) {
        if (!check[i]) {
            spf[i] = i;
            for (ll j = i; j*i < N; j += 2) {
                if (!check[j*i]) {
                    spf[j*i] = i;
                    check[j*i] = true;
                }
            }
        } 
    }
}

unordered_map<ll, ll> primeFact(ll n) {
    unordered_map<ll, ll> cnt;
    while (n > 1) {
        cnt[spf[n]]++;
        n = n/spf[n];
    }
    return cnt;
}

ll nCr(ll n, ll r) {
    if (r > n) return 0;
    ll upore = fact[n];
    ll niche = (invFact[r] * invFact[n-r]) % M;
    return (upore*niche) % M;
}

signed main() {
    ios_base::sync_with_stdio(); cin.tie();
    ll tt = 1; cin >> tt;
    sieve();

    fact[0] = 1;
    for (ll i = 1; i < N; i++) fact[i] = (fact[i-1]*i) % M;
    
    invFact[N-1] = bigMod(fact[N-1], M-2);
    for (ll i = N-2; i >= 0; i--) invFact[i] = (invFact[i+1]*(i+1)) % M;

    test:
    while (tt--) {
        ll n, k; cin >> n >> k;

        ll arr[n];
        unordered_map<ll, ll> cnt;
        for (auto &u : arr) {
            cin >> u;
            auto it = primeFact(u);
            for (auto &u : it) cnt[u.first]++;
        }

        ll ans = 0;
        for (auto &u : cnt) {
            ll curr = (nCr(n, k) - nCr(n-u.second, k) + M) % M;
            ll temp = (curr * u.first) % M;
            ans = (ans + temp) % M;
        }
        
        cout << ans << "\n";        
    }
}
