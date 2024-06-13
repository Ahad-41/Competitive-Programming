#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1; cin >> tt;

    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";
        answer();
    }

    return 0;
}

void answer() {
    ll n, m; cin >> n >> m;
    
    ll xorValue;
    for (ll i = 1; i <= n; i++) {
        ll sum = 0;
        for (ll j = 1; j <= m; j++) {
            ll a; cin >> a;
            sum += a;
        }

        if (i == 1) xorValue = sum;
        else xorValue ^= sum;
    }

    cout << (xorValue > 0 ? "Alice" : "Bob") << endl;
}
