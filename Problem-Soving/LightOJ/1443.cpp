1#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void answer();

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1; cin >> tt;

    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i << ":\n";
        answer();
    }

    return 0;
}

void answer() {
    ll n; cin >> n;

    vector<ll> divisor;
    divisor.push_back(1);

    for (ll i = 2; i*i <= n; i++) {
        ll pow = 0;
        while (n % i == 0) {
            n /= i;
            pow++;
        }
        
        bool forward = false;
        ll x = i;
        ll sz = divisor.size(); 
        while (pow) {
            if (forward) {
                for (ll i = 0; i < sz; i++) divisor.push_back(divisor[i] * x);
            }
            else {
                for (ll i = sz-1; i >= 0; i--) divisor.push_back(divisor[i] * x);
            }

            forward = !forward;
            x *= i;
            pow--;
        }
    }
    if (n > 1) {
        for(ll i = divisor.size()-1; i >= 0; i--) divisor.push_back(n * divisor[i]);
    }

    for (auto &u : divisor) cout << u << " ";
    cout << endl;
}
