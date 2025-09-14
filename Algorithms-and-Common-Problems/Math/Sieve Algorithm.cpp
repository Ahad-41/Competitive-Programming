const ll N = 1e7+5;
ll check[N], num[N];

void sieve() {
    check[0] = check[1] = 1;
    for (ll i = 2; i < N; i++) {
        if (!check[i]) {
            for (ll j = i*i; j < N; j += i) check[j] = 1;
        }
    }
}
