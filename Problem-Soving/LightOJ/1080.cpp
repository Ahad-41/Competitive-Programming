#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void answer();
const ll N = 1e5+7;
bool tree[4*N];

void query1(ll currNode, ll left, ll right, ll i, ll j) {
    if (left == i and right == j) {
        tree[currNode] = !tree[currNode];
        return;
    }
    
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;

    if (j <= mid) query1(leftNode, left, mid, i, j);
    else if (i > mid) query1(rightNode, mid+1, right, i, j);

    else {
        query1(leftNode, left, mid, i, mid);
        query1(rightNode, mid+1, right, mid+1, j);
    }
}

bool query2(ll currNode, ll left, ll right, ll i) {
    if (left == i and right == i) return tree[currNode];
    
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;

    if (tree[currNode]) {
        tree[leftNode] = !tree[leftNode];
        tree[rightNode] = !tree[rightNode];
        tree[currNode] = false;
    }

    return i <= mid ? query2(leftNode, left, mid, i) : query2(rightNode, mid+1, right, i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ":" << endl;
        answer();
    }    
}

void answer() {
    memset(tree, false, sizeof(tree));

    string s; cin >> s;
    ll n = s.size();

    for (ll i = 1; i <= n; i++) {
        if (s[i-1] == '1') {
            query1(1, 1, n, i, i);
        }
    }
    
    ll q; cin >> q;
    while (q--) {
        char ch; cin >> ch;
        if (ch == 'I') {
            ll i, j; cin >> i >> j;
            query1(1, 1, n, i, j);
        }
        else {
            ll i; cin >> i;
            cout << query2(1, 1, n, i) << endl;
        }
    }
}
