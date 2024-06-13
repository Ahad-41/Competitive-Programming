vector<ll> prime;
const ll N = 1e7+7;
bool check[N];
void sieve() {
    for (ll i = 3; i < N; i += 2) 
        if (!check[i])
            for (ll j = i*i; j < N; j += i) check[j] = true;

    prime.push_back(2);
    for (ll i = 3; i < N; i += 2) 
        if (!check[i]) prime.push_back(i);
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
