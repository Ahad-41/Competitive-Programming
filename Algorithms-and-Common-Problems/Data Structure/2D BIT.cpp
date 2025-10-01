#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1005;
ll n, q, tree[N][N];
char arr[N][N];

ll query(ll y, ll x) {
    ll sum = 0;
    for (ll i = y; i > 0; i -= i & -i) {
        for (ll j = x; j > 0; j -= j & -j) {
            sum += tree[i][j];
        }
    }
    return sum;
}

void update(ll y, ll x, ll value) {
    for (ll i = y; i <= n; i += i & -i) {
        for (ll j = x; j <= n; j += j & -j) {
            tree[i][j] += value;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '*') update(i, j, 1);
        }
    }

    while (q--) {
        ll type; cin >> type;
        if (type == 1) {
            ll y, x; cin >> y >> x;
            if (arr[y][x] == '*') {
                arr[y][x] = '.';
                update(y, x, -1);
            } 
            else {
                arr[y][x] = '*';
                update(y, x, 1);
            }
        } 
        else {
            ll y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
            cout << query(y2, x2) - query(y1-1, x2) - query(y2, x1-1) + query(y1-1, x1-1) << "\n";
        }
    }
}
