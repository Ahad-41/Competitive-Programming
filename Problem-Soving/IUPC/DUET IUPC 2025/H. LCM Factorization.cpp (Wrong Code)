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

map<ll, ll> primeFact(ll n) {
    map<ll, ll> cnt;
    while (n > 1) {
        cnt[spf[n]]++;
        n = n/spf[n];
    }
    return cnt;
}

signed main() {
    ios_base::sync_with_stdio(); cin.tie();
    ll tt = 1; 
    cin >> tt;
    sieve();

    fact[0] = 1;
    for (ll i = 1; i < N; i++) fact[i] = (fact[i-1] * i) % M;
    // invFact[N-1] = bigMod(N-1, M-2);
    // for (ll i = N-2; i >= 0; i--) invFact[i] = (invFact[i+1]*(i+1)) % M;

    test:
    while (tt--) {
        ll n, k; cin >> n >> k;

        ll arr[n], total = 0;
        map<ll, ll> cnt;
        for (auto &u : arr) {
            cin >> u;
            if (u == 1) {
                total++;
                continue;
            }
            auto it = primeFact(u);
            for (auto &u : it) cnt[u.first]++;
        }
        total += cnt.size();

        ll ans = 0;
        for (auto &u : cnt) {
            if (u.second == 1) {
                ll temp = (u.first * (n-k+1)) % M;
                ans = (ans + temp) % M;
            }
            else {
                ll temp = (u.first * (total-1)) % M;
                temp = (temp * u.second) % M;
                ans = (ans + temp) % M;
            }
        }

        // ll pref[n+1] = {0};
        // for (ll i = 2; i <= k; i++) {
        //     ll upore = fact[k];
        //     ll niche = (fact[i] * fact(k-i)) % M;
        //     pref[i] = (upore*niche) % M;
        //     pref[i] = (pref[i]+pref[i-1]) % M;
        // }

        for (auto &u : cnt) {
            if (u.second == 1) continue;
            ll low = max(2LL, k-(total-1));
            ll high = min(k, u.second);
            ll curr = 0;

            for (ll i = low; i <= high; i++) {
                ll upore = fact[k];
                ll niche = (fact[i] * fact[k-i]) % M;
                ll temp = (upore/niche);
                curr = (curr+temp) % M;
            } 

            ll temp = (curr * u.first) % M;
            ans = (ans + temp) % M;
        }
        
        cout << ans << "\n";
        // for (auto &u : cnt) cout << u.first << " " << u.second << "\n";
        
    }
}
