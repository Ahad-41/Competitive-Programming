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
