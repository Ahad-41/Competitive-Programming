#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e6+7;
bool check[N];
vector<ll> prime;

void sieve() {
    for (ll i = 3; i*i < N; i += 2) {
        if (!check[i]) {
            for (ll j = i*i; j < N; j += i) check[j] = true;
        }
    }

    prime.push_back(2);
    for (ll i = 3; i < N; i += 2) if (!check[i]) prime.push_back(i);
}

void segmentedSieve(ll l, ll r) {
    ll limit = r-l+1;
    bool isPrime[limit];
    memset(isPrime, true, sizeof(isPrime));

    for (ll i = 0; prime[i]*prime[i] <= r; i++) {
        ll base = (l / prime[i]) * prime[i];
        if (base < l) base += prime[i];

        for (ll j = base; j <= r; j += prime[i]) isPrime[j-l] = false;
        if (base == prime[i]) isPrime[base-l] = true;
    }

    for (ll i = 0; i < limit; i++) if (isPrime[i]) cout << l+i << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    int tc; cin >> tc;

    test:
    while (tc--) {
        ll m, n; cin >> m >> n;
        if (m == 1) m++;
        segmentedSieve(m, n);
    }
}
