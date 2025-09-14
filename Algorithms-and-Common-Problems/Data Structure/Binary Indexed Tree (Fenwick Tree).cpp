#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7;
ll n, q, tree[N];

ll query(ll index) {
    ll sum = 0;
    while (index) {
        sum += tree[index];
        index -= index & (-index); 
    }
    return sum;
}

void update(ll index, ll value) {
    while (index <= n) {
        tree[index] += value;
        index += index & (-index);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;

    ll arr[n];
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }

    while (q--) {
        
    }
}
