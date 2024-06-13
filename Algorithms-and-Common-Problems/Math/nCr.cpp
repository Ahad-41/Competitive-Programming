ll nCr(ll n, ll r) {
    double value = 1;
    for(ll i = 1; i <= r; i++){
        value = value * (n - r + i) / i;
    }
    return (ll)value;
}
