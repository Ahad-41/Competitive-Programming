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

ll sumOfDivisor(ll n) {
    ll totalSum = 1, count = 0, sum = 1;
    for (auto &u : prime) {
        if (u*u > n) break;
        count = 0;
        sum = 1;
        while (n % u == 0) {
            count++;
            sum += pow(u, count);
            n /= u;
        }
        totalSum *= sum;
    }
    if (n > 2) totalSum *= (n+1);
    
    return totalSum;
}
