const ll N = 1e7+7;
ll spf[N];
void sieve() {
    for (ll i = 1; i < N; i++) spf[i] = i;
    for (ll i = 4; i < N; i += 2) spf[i] = 2;

    for (ll i = 3; i*i < N; i++) {
        if (spf[i] == i) {
            for (ll j = i*i; j < N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }   
        }
    }
}
