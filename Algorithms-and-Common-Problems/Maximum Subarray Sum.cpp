#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    
    ll arr[n];
    for (auto &u : arr) cin >> u;

    ll maxSum = 0, tempSum = 0;
    for (ll i = 0; i < n; i++) {
        tempSum = max(arr[i], tempSum+arr[i]);
        maxSum = max(maxSum, tempSum);
    }

    cout << maxSum << "\n";
}


