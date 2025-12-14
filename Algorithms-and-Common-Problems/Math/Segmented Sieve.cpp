#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e7+5;
bool isComposite[N];
vector<ll> prime;

void sieve() {
	for (ll i = 2; i < N; i++) {
		if (!isComposite[i]) prime.push_back(i);
		for (ll j = 0; j < prime.size() and i * prime[j] < N; j++) {
			isComposite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
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


