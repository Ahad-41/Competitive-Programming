// https://codeforces.com/problemset/problem/242/E
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+5;
ll arr[N];

struct info {
    ll lazy = 0, cnt[21] = {0};
} tree[N*4];

void push(ll currNode, ll left, ll right) {
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;

    for (ll i = 0; i <= 20; i++) {
        if (tree[currNode].lazy & (1LL << i)) {
            tree[leftNode].lazy ^= (1LL << i);
            tree[rightNode].lazy ^= (1LL << i);

            tree[leftNode].cnt[i] = (mid-left+1)-tree[leftNode].cnt[i];
            tree[rightNode].cnt[i] = (right-mid)-tree[rightNode].cnt[i];
        }
    }

    tree[currNode].lazy = 0;
}

void segmentTree(ll currNode, ll left, ll right) {
    if (left == right) {
        for (ll i = 0; i <= 20; i++) {
            if (arr[left] & (1LL << i)) tree[currNode].cnt[i]++;
        }
        return;
    } 
    
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    segmentTree(leftNode, left, mid);
    segmentTree(rightNode, mid+1, right);

    for (ll i = 0; i <= 20; i++) {
        tree[currNode].cnt[i] = tree[leftNode].cnt[i]+tree[rightNode].cnt[i];
    }
}

info query(ll currNode, ll left, ll right, ll i, ll j) {
    if (i > right or j < left) return {};
    if (left >= i and right <= j) return tree[currNode];
    push(currNode, left, right);
    
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    info leftSum = query(leftNode, left, mid, i, j);
    info rightSum = query(rightNode, mid+1, right, i, j);

    info ans;
    for (ll i = 0; i <= 20; i++) ans.cnt[i] = leftSum.cnt[i]+rightSum.cnt[i];
    return ans;
}

void update(ll currNode, ll left, ll right, ll i, ll j, ll newValue) {
    if (i > right or j < left) return;
    if (left >= i and right <= j) {
        for (ll i = 0; i <= 20; i++) {
            if (newValue & (1LL << i)) {
                tree[currNode].lazy ^= (1LL << i);
                tree[currNode].cnt[i] = (right-left+1)-tree[currNode].cnt[i];
            }
        }
        return;
    }

    push(currNode, left, right);

    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    update(leftNode, left, mid, i, j, newValue);
    update(rightNode, mid+1, right, i, j, newValue);
    
    for (ll i = 0; i <= 20; i++) tree[currNode].cnt[i] = tree[leftNode].cnt[i]+tree[rightNode].cnt[i];
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;

    for (ll i = 1; i <= n; i++) cin >> arr[i];
    segmentTree(1, 1, n);

    ll q; cin >> q;
    while (q--) {
        ll type; cin >> type;
        if (type == 1) {
            ll l, r; cin >> l >> r;

            auto it = query(1, 1, n, l, r);
            ll ans = 0;
            for (ll i = 0; i <= 20; i++) ans += it.cnt[i]*(1LL << i);

            cout << ans << "\n";
        }
        else {
            ll l, r, x; cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        }
    }
}
