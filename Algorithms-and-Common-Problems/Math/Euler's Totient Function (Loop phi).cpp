#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll phi(ll n) {
    ll totalCoprime = n;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            totalCoprime -= totalCoprime/i;
        }
    }

    if (n > 1) totalCoprime -= totalCoprime/n;
    return totalCoprime;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    cout << phi(n) << "\n"; 
}
