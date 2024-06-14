// Problem Link: https://atcoder.jp/contests/abc357/tasks/abc357_f

// May be I won't be a good programmer, but I will be a good human being.
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll M = 998244353;
const ll N = 2e5+5;

struct node {
    ll sumA = 0, sumB = 0, ans = 0, propA = 0, propB = 0;
} tree[N*4];

node merge(node x, node y) {
    node ans;
    ans.sumA = (x.sumA + y.sumA) % M;
    ans.sumB = (x.sumB + y.sumB) % M;
    ans.ans = (x.ans + y.ans) % M;
    ans.propA = ans.propB = 0;
    return ans;
}

void propagate(ll currNode, ll left, ll right) {
    ll diff = right - left + 1;
    tree[currNode].sumA = (tree[currNode].sumA + ((tree[currNode].propA * diff) % M)) % M;
    tree[currNode].ans = (tree[currNode].ans + ((tree[currNode].propA * tree[currNode].sumB) % M)) % M; 
    
    tree[currNode].sumB = (tree[currNode].sumB + ((tree[currNode].propB * diff) % M)) % M;
    tree[currNode].ans = (tree[currNode].ans + ((tree[currNode].propB * tree[currNode].sumA) % M)) % M;

    if (left != right) {
        ll leftNode = currNode*2, rightNode = currNode*2 + 1;
        tree[leftNode].propA = (tree[leftNode].propA + tree[currNode].propA) % M;
        tree[leftNode].propB = (tree[leftNode].propB + tree[currNode].propB) % M;
        tree[rightNode].propA = (tree[rightNode].propA + tree[currNode].propA) % M;
        tree[rightNode].propB = (tree[rightNode].propB + tree[currNode].propB) % M;
    }

    tree[currNode].propA = tree[currNode].propB = 0;
}

ll query(ll currNode, ll left, ll right, ll i, ll j) {
    propagate(currNode, left, right);
    if (i > right || j < left) return 0;
    if (left >= i and right <= j) return tree[currNode].ans;
    
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    ll leftSum = query(leftNode, left, mid, i, j);
    ll rightSum = query(rightNode, mid + 1, right, i, j);

    return (leftSum + rightSum) % M;
}

void updateA(ll currNode, ll left, ll right, ll i, ll j, ll newValue) {
    propagate(currNode, left, right);
    if (i > right || j < left) return;
    if (left >= i and right <= j) {
        tree[currNode].propA += newValue;
        return propagate(currNode, left, right); 
    }

    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    updateA(leftNode, left, mid, i, j, newValue);
    updateA(rightNode, mid+1, right, i, j, newValue);
    
    tree[currNode] = merge(tree[leftNode], tree[rightNode]);
}

void updateB(ll currNode, ll left, ll right, ll i, ll j, ll newValue) {
    propagate(currNode, left, right);
    if (i > right || j < left) return;
    if (left >= i and right <= j) {
        tree[currNode].propB += newValue;
        return propagate(currNode, left, right); 
    }

    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    updateB(leftNode, left, mid, i, j, newValue);
    updateB(rightNode, mid+1, right, i, j, newValue);
    
    tree[currNode] = merge(tree[leftNode], tree[rightNode]);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, q; cin >> n >> q;

    for (ll i = 1; i <= n; i++) {
        ll a; cin >> a;
        updateA(1, 1, n, i, i, a);
    }
    for (ll i = 1; i <= n; i++) {
        ll b; cin >> b;
        updateB(1, 1, n, i, i, b);
    }

    while (q--) {
        ll type; cin >> type;
        if (type != 3) {
            ll i, j, v; cin >> i >> j >> v;
            type == 1 ? updateA(1, 1, n, i, j, v) : updateB(1, 1, n, i, j, v);
        }
        
        else {
            ll i, j; cin >> i >> j;
            cout << query(1, 1, n, i, j) << "\n";
        }
    }
}
