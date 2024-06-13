#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void answer();

vector<ll> subsetSum(vector<ll> &curr) {
    ll n = curr.size();
    vector<ll> sum;

    for (ll i = 0; i < (1 << n); i++) {
        ll taken = 0;

        for (ll j = 0; j < n; j++) {
            if ((1 << j) & i) taken += curr[j];
        }
        sum.push_back(taken);
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        answer();
    }
}

void answer()
{
    ll n, w; cin >> n >> w;
    
    vector<ll> even, odd;
    for (ll i = 1; i <= n; i++) {
        ll a; cin >> a;
        if (i & 1) odd.push_back(a);
        else even.push_back(a);
    }

    vector<ll> oddSum = subsetSum(odd);
    vector<ll> evenSum = subsetSum(even);
    sort(oddSum.begin(), oddSum.end());

    ll count= 0;
    for (auto u : evenSum) {
        ll need = w - u;
        count += upper_bound(oddSum.begin(), oddSum.end(), need) - oddSum.begin();
    }

    cout << count << endl;
}
