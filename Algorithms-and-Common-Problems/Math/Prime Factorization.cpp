const ll N = 1e7+7;
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
 
map<ll, ll> primeFactorization(ll n) {
    map<ll, ll> cnt;
    for (auto &u : prime) {
        if (u*u > n) break;
        while (n % u == 0) {
            cnt[u]++;
            n /= u;
        }
    }
    if (n > 1) cnt[n]++;
    return cnt;
}
