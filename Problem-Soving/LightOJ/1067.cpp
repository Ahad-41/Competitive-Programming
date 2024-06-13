#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

const ll M = 1000003;
const ll N = 1e6+5;
ll fact[N];


ll bigMod(ll base, ll power) {
    if (!power) return 1; // base case
    ll result = bigMod(base, power/2);
    result = (result * result) % M;
    if (power & 1) result = (result * base) % M;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = 1;
    for (ll i = 1; i < N; i++) fact[i] = (fact[i-1] * i) % M;
    
    ll tt = 1;
    cin >> tt;

    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";
        answer();
    }

    return 0;
}

void answer() {
    ll n, r; cin >> n >> r;
    
    ll ans = (fact[r] * fact[n-r]) % M;
    ans = (fact[n] * bigMod(ans, M-2)) % M;

    cout << ans << endl;
}
