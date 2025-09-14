#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 4e5+5;
struct info {
    ll prop = -1, sum = 0;
} tree[N*4];

void propagate(ll currNode, ll left, ll right) {
    ll leftNode = currNode*2, rightNode = currNode*2+1;
    ll mid = left + (right-left) / 2;

    tree[leftNode].sum = (mid-left+1)*tree[currNode].prop;
    tree[rightNode].sum = (right-mid)*tree[currNode].prop;
    tree[leftNode].prop = tree[rightNode].prop = tree[currNode].prop;
    tree[currNode].prop = -1;
}

ll query(ll currNode, ll left, ll right, ll i, ll j, ll carry = 0) {
    if (i > right or j < left) return 0;
    if (left >= i and right <= j) return tree[currNode].sum;
    if (tree[currNode].prop != -1) propagate(currNode, left, right);
    
    ll leftNode = currNode*2, rightNode = currNode*2+1;
    ll mid = left + (right-left)/2;
    ll leftSum = query(leftNode, left, mid, i, j, carry+tree[currNode].prop);
    ll rightSum = query(rightNode, mid+1, right, i, j, carry+tree[currNode].prop);

    return leftSum+rightSum;
}

void update(ll currNode, ll left, ll right, ll i, ll j, ll newValue) {
    if (i > right or j < left) return;
    if (left >= i and right <= j) {
        tree[currNode].sum = (right-left+1)*newValue;
        tree[currNode].prop = newValue;
        return;
    }
    if (tree[currNode].prop != -1) propagate(currNode, left, right);

    ll leftNode = currNode*2, rightNode = currNode*2+1;
    ll mid = left+(right-left)/2;
    update(leftNode, left, mid, i, j, newValue);
    update(rightNode, mid+1, right, i, j, newValue);
    
    tree[currNode].sum = tree[leftNode].sum+tree[rightNode].sum;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tc; cin >> tc;

    test:
    while (tc--) {
        ll n, q; cin >> n >> q;

        for (ll i = 1; i <= n*4; i++) {
            tree[i].sum = 0;
            tree[i].prop = -1;
        }

        while (q--) {
            ll type; cin >> type;
            if (type == 1) {
                ll i, j, v; cin >> i >> j >> v;
                update(1, 1, n, i, j, v);
            }
            else {
                ll i, j; cin >> i >> j;
                ll a = query(1, 1, n, i, j), b =  (j-i+1);
                ll gcd = __gcd(a, b);
                a /= gcd; 
                b /= gcd;
                if (b == 1) cout << a << "\n";
                else cout << a << "/" << b << "\n";
            }
        }
    }
}
