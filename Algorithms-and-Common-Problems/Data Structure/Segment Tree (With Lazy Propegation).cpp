#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+5;
ll arr[N];

struct info {
    long long prop, sum;
} tree[N*4];

void segmentTree(ll currNode, ll left, ll right) {
    if (left == right) {
        tree[currNode].sum = arr[left];
        return;
    } 
    
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    segmentTree(leftNode, left, mid);
    segmentTree(rightNode, mid+1, right);

    tree[currNode].sum = tree[leftNode].sum+tree[rightNode].sum;
}

ll query(ll currNode, ll left, ll right, ll i, ll j, ll carry = 0) {
    if (i > right or j < left) return 0;
    if (left >= i and right <= j) {
        return tree[currNode].sum + carry*(right-left+1);
    }
    
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    ll leftSum = query(leftNode, left, mid, i, j, carry+tree[currNode].prop);
    ll rightSum = query(rightNode, mid+1, right, i, j, carry+tree[currNode].prop);

    return leftSum+rightSum;
}

void update(ll currNode, ll left, ll right, ll i, ll j, ll newValue) {
    if (i > right or j < left) return;
    if (left >= i and right <= j) {
        tree[currNode].sum += ((right-left+1)*newValue);
        tree[currNode].prop += newValue;
        return;
    }

    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    update(leftNode, left, mid, i, j, newValue);
    update(rightNode, mid+1, right, i, j, newValue);
    
    tree[currNode].sum = tree[leftNode].sum + tree[rightNode].sum + (right-left+1) * tree[currNode].prop;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, q; cin >> n >> q;

    for (ll i = 1; i <= n; i++) cin >> arr[i];
    segmentTree(1, 1, n);

    while (q--) {
        
    }
}
