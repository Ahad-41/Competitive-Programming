#include <bits/stdc++.h>
using namespace std;
typedef int ll;

const ll N = 2e6+9;
ll phi[N];
bool mark[N];
ll bamboo[N];

void sievePhi() {
    for (ll i = 1; i < N; i++) phi[i] = i; 
    phi[1] = 0;
    for (ll i = 2; i < N; i++) {
        if (mark[i] == true) continue;
        for (ll j = i; j < N; j += i) {
            mark[j] = true;
            phi[j] = phi[j] / i * (i-1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (auto &u : bamboo) u = 1e9;
    sievePhi();
    for (ll i = N-2; i >= 1; i--) bamboo[phi[i]] = i;

    ll curr = -1;
    for (ll i = N-2; i >= 1; i--) {
        bamboo[i] = min(bamboo[i], bamboo[i + 1]);
    }

    ll tt = 1; cin >> tt;
    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";

        ll n; cin >> n;
        long long int sum = 0;
        while (n--) {
            ll a; cin >> a;
            sum += bamboo[a];
        }

        cout << sum << " Xukha\n";
    }

    return 0;
}
