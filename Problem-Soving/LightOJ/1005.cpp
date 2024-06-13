#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void answer();

vector<ll> pascal[35];
ll fact[25];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    pascal[0].push_back(1);
    for (ll i = 1; i <= 30; i++) {
        pascal[i].push_back(1);
        for(ll j = 0; j < pascal[i-1].size()-1; j++) {
            pascal[i].push_back(pascal[i-1][j] + pascal[i-1][j+1]);
        }
        pascal[i].push_back(1);
    }

    fact[0] = 1;
    for (ll i = 1; i <= 20; i++) fact[i] = i * fact[i-1];

    ll tt = 1; cin >> tt;
    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";
        answer();
    }

    return 0;
}

void answer() {
    ll n, k; cin >> n >> k;
    
    ll ans = 0;
    if (n >= k) ans = pascal[n][k] * pascal[n][k] * fact[k];
    cout << ans << endl;
}
