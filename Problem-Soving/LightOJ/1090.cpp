#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

ll factFunc(ll n, ll m) {
    ll cnt = 0;
    while (n) {
        cnt += n / m;
        n /= m;
    }
    return cnt;
}

ll normalFunc(ll  n,  ll m) {
    ll cnt = 0;
    while (n % m  == 0) {
        cnt++;
        n /= m;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll i = 1; i <= tt; i++) {
        cout << "Case "<< i <<  ": ";
        answer();
    }

    return 0;
}

void answer() {
    ll n, r, p, q; cin >> n >>  r  >> p  >> q;
    
    ll n2 = factFunc(n, 2);
    ll n5 = factFunc(n, 5);

    ll r2 = factFunc(r, 2);
    ll r5 = factFunc(r, 5);

    ll n_r2 = factFunc(n-r, 2);
    ll n_r5 = factFunc(n-r, 5);

    ll p2 = normalFunc(p, 2) * q;
    ll p5 = normalFunc(p, 5) * q;

    ll two = n2 + p2 - r2 - n_r2;
    ll five = n5 + p5 - r5 - n_r5;
    
    cout << min(two, five) <<  endl;
}
