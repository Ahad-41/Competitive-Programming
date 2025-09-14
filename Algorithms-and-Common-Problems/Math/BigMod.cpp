const ll M = 1e9+7;
ll bigMod(ll base, ll power) {
    if (!power) return 1;
    ll result = bigMod(base, power/2);
    result = (result * result) % M;
    if (power & 1) result = (result * base) % M;
    return result;
}

ll binExp(ll base, ll power) {
    ll result = 1;
    while (power) {
        if (power & 1) result = (result * 1LL * base) % M;
        base = (base * 1LL * base) % M;
        power /=  2;
    }
    return result;
} 
