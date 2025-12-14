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

ll divisorCount(ll n) {
    ll totalDivisor = 1;
    for (ll i = 0; i < N; i++) {
        if (prime[i]*prime[i] > n) break;
        
        if (n % prime[i] == 0) {
            ll curr = 0;
            while (n > 1 and n % prime[i] == 0) {
                curr++;
                n /= prime[i];
            }
            totalDivisor *= (curr+1);
        }
    }
    if (n != 1) totalDivisor *= 2;
    
    return totalDivisor;
}
