// May be I won't be a good programmer, but I will be a good human being.
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1000001;
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

ll primeFactorization(ll n) {
    map<ll, ll> cnt;
    for (auto &u : prime) {
        if (u*u > n) break;
        while (n % u == 0) {
            cnt[u]++;
            n /= u;
        }
    }
    if (n > 1) cnt[n]++;
    
    ll gcd = 0;
    for (auto &u : cnt) gcd = __gcd(gcd, u.second);
    return gcd;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();

    ll t = 1; cin >> t;
    for (ll i = 1; i <= t; i++) {
        ll n; cin >> n;
        ll ans = primeFactorization(abs(n));
        if (n < 0) while (ans % 2 == 0) ans >>= 1;
        cout << "Case " << i <<  ": " << ans << "\n";
    }
}
