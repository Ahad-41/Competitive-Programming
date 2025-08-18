#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e7+7;
ll spf[N], counter[N];

void sieve() {
    for (ll i = 1; i < N; i++) spf[i] = i;
    for (ll i = 2; i*i < N; i++) {
        if (spf[i] == i) {
            for (ll j = i*i; j < N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();

    ll tc; cin >> tc;
    while (tc--) {
        ll n; cin >> n;
        for (ll i = 0; i <= 10*n; i++) counter[i] = 0;

        ll arr[n];
        for (auto &u : arr) cin >> u;
        sort(arr, arr+n);

        ll badPair = 0;
        for (ll i = n-1; i >= 0; i--) {
            if (arr[i] == 1) break;

            ll cnt = 1;
            while (i > 0 and arr[i] == arr[i-1]) cnt++, i--;

            vector<pair<ll,ll>> primeFact;
            vector<ll> mxFact;
            ll num = arr[i];
            while (num > 1) {
                ll p = spf[num], j = 0, product = p;
                while (num % p == 0) {
                    num /= p;
                    if (j & 1) product *= p;
                    j++;
                }
                primeFact.push_back({p, j});
                mxFact.push_back(product);
            }

            vector<ll> divisors, temp;
            divisors.push_back(1);
            for (auto &u : primeFact) {
                temp.clear();
                ll now = 1;
                for (ll k = 0; k <= u.second; k++, now *= u.first) {
                    for (auto &v : divisors) temp.push_back(v*now);
                }
                divisors = temp;
            }

            ll sz = mxFact.size();
            ll tempCnt = 0;
            for (ll mask = 1; mask < (1LL<<sz); mask++) {
                ll product = 1;
                ll parity = 0;
                for (ll j = 0; j < sz; j++) {
                    if (mask & (1LL<<j)) {
                        product *= mxFact[j];
                        parity ^= 1;
                    }
                }
                if (product > n*10) continue;
                if (__builtin_popcount(mask) & 1) tempCnt += counter[product];
                else tempCnt -= counter[product];
            }

            badPair += cnt * tempCnt;
            badPair += cnt * (cnt+1) / 2;
            for (auto &u : divisors) counter[u] += cnt;
        }

        cout << n*(n+1)/2 - badPair << "\n";
    }
}
