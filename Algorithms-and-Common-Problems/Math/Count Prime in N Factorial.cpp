ll countPrimeInFactorial(ll n, ll p) {
    ll count = 0;
    for (ll power = p; power <= n; power *= p) {
        count += n / power;
        if (power > n / p) break;  // Avoid overflow
    }
    return count;
}
