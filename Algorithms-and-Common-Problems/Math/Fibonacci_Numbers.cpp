#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll M = 1e9+7;
map<ll, ll> fib;

ll func(ll n) {
    if (fib.find(n) != fib.end()) return fib[n];
    ll k = n / 2;
	
    if (n % 2 == 0) { // n = 2*k
        return fib[n] = (func(k) * func(k) + func(k-1) * func(k-1)) % M;
    } 
    else { // n = 2*k+1
	return fib[n] = (func(k)*func(k+1) + func(k-1)*func(k)) % M;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;

    fib[0] = fib[1] = 1;
    if (n == 0) cout << 0 << endl;
    else cout << func(n-1) << endl;

    return 0;
}
