#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

ll fact[25];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1; cin >> tt;

    fact[0] = 1;
    for (ll i = 1; i <= 20; i++) fact[i] = fact[i-1] * i;

    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";
        answer();
    }

    return 0;
}

void answer() {
    ll n; cin >> n;

    vector<ll> v;
    for (ll i = 20; i >= 0; i--) {
        if (fact[i] <= n) {
            n -= fact[i];
            v.push_back(i);
        }
    }

    if (n) {
        cout << "impossible" << endl;
        return;
    }
    
    n = v.size();
    for (ll j = n-1; j >= 0; j--) {
        cout << v[j];
        cout << (j ? "!+" : "!\n");
    }  
}
