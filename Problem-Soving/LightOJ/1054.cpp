#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

const ll M = 1e9+7;
map<ll, ll> cnt;

void primeFact(ll n) {
    while (n % 2 == 0) {
        cnt[2]++;
        n /= 2;
    }
    for (ll i = 3; i*i <= n; i += 2)  {
        while (n % i == 0) {
            cnt[i]++;
            n /= i;
        }
    }
    if (n > 1) cnt[n]++;
}

ll binExp(ll base, ll power) {
    if (!power) return 1;
    ll result = binExp(base, power/2);
    result = (result * result) % M;
    if (power & 1) result = (result*base) % M;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i <<   ": ";
        answer();
    }

    return 0;
}

void answer() {
    ll n, m; cin >> n >> m;
    cnt.clear();
    
    primeFact(n);
    for (auto &u : cnt) u.second *= m;

    ll totalSum = 1;
    for (auto &u : cnt) {
        ll temp = binExp(u.first, u.second+1)  - 1;
        if (temp < 0) temp += M;
        temp *= binExp(u.first-1, M-2);

        totalSum = (totalSum * (temp % M)) % M;
    }

    cout << totalSum << endl;
}
