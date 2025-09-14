#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e6+5;
ll phi[N];
bool mark[N];

void sievePhi(ll n) {
    for (ll i = 1; i <= n; i++) phi[i] = i; 

    for (ll i = 2; i <= n; i++) {
        if (mark[i] == true) continue;

        for (ll j = i; j <= n; j += i) {
            mark[j] = true;
            phi[j] = phi[j]/i * (i-1);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    sievePhi(n);

    cout << phi[10] << "\n";
}
