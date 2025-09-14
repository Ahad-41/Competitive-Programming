#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7;
vector<ll> primes;

void sieve() {
    bool isPrime[N];
    memset(isPrime, true, sizeof(isPrime));

    for (ll i = 3; i*i < N; i += 2) {
        if (isPrime[i]) {
            for (ll j = i*i; j <= N; j += i) isPrime[j] = false;
        }   
    } 

    primes.push_back(2);
    for (ll i = 3; i <= N; i += 2) if (isPrime[i]) primes.push_back(i);
}

void segmentedSieve (ll l, ll r) {
    ll limit = r-l+1;
    bool isPrime[limit];
    memset(isPrime, true, sizeof(isPrime));
    
    for (ll i = 0; primes[i] * primes[i] <= r; i++) {
        ll base = (l/primes[i]) * primes[i];
        if (base < l) base += primes[i];

        for (ll j = base; j <= r; j += primes[i]) isPrime[j-l] = false;
        if (base == primes[i]) isPrime[base-l] = true;
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
