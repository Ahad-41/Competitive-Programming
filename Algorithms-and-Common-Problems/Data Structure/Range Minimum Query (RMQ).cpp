const ll N = 1e6 + 7;
const ll LG = 22;
ll arr[N], t[N][LG];
void build(ll m) {
    for (ll i = 1; i <= m; i++) t[i][0] = arr[i];
    for (ll k = 1; k < LG; k++) {
        for (ll i = 1; i + (1 << k) - 1 <= m; i++) {
            t[i][k] = min(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
        }
    }
}
 
ll query(ll l, ll r) {
    ll k = 31 - __builtin_clz(r - l + 1);
    return min(t[l][k], t[r - (1 << k) + 1][k]);
}
