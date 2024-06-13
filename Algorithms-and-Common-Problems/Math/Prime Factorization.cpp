const ll N = 1e7+7;
bool check[N];
vector<ll> prime;
void sieve() {
    for (ll i = 3; i < N; i += 2) 
        if (!check[i])
            for (ll j = i*i; j < N; j += i) check[j] = true;
 
    prime.push_back(2);
    for (ll i = 3; i < N; i += 2) 
        if (!check[i]) prime.push_back(i);
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
