// https://codeforces.com/problemset/problem/1891/F
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 5e5+7;
vector<ll> adjList[N], traverse;
ll parent[N], indx[N], subTreeSize[N], sz[N];

void dfs(ll currNode) {
    subTreeSize[currNode] = 1;
    traverse.push_back(currNode);
    for (auto &u : adjList[currNode]) {
        if (u == parent[currNode]) continue;
        dfs(u);
        subTreeSize[currNode] += subTreeSize[u];
    }
}

struct info {
    ll prop = 0, sum = 0;
} tree[N*3];

ll query(ll currNode, ll left, ll right, ll i, ll j, ll carry = 0) {
    if (i > right || j < left) return 0;
    if (left >= i and right <= j) {
        return tree[currNode].sum + carry * (right - left + 1);
    }
    
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    ll leftSum = query(leftNode, left, mid, i, j, carry + tree[currNode].prop);
    ll rightSum = query(rightNode, mid + 1, right, i, j, carry + tree[currNode].prop);

    return leftSum+rightSum;
}

void update(ll currNode, ll left, ll right, ll i, ll j, ll newValue) {
    if (i > right || j < left) return;
    if (left >= i and right <= j) {
        tree[currNode].sum += ((right - left + 1) * newValue);
        tree[currNode].prop += newValue;
        return;
    }

    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    update(leftNode, left, mid, i, j, newValue);
    update(rightNode, mid+1, right, i, j, newValue);
    
    tree[currNode].sum = tree[leftNode].sum + tree[rightNode].sum + (right - left + 1) * tree[currNode].prop;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ll tt; cin >> tt;

    test:
    while (tt--) {
        ll q; cin >> q;

        vector<ll> qq[q];
        ll n = 1;
        for (auto &u : qq) {
            ll type; cin >> type;
            u.push_back(type);
            if (type == 1) {
                ll v; cin >> v;
                u.push_back(v);
                n++;
            }
            else {
                ll v, x; cin >> v >> x;
                u.push_back(v);
                u.push_back(x);
            }
        }

        for (ll i = 1; i <= n; i++) adjList[i].clear();
            
        ll curr = 2;
        for (auto &u : qq) {
            if (u[0] == 2) continue;
            adjList[u[1]].push_back(curr);
            parent[curr] = u[1];
            curr++;
        }
        
        parent[1] = 1;
        traverse.clear();
        traverse.push_back(0);
        dfs(1);

        for (ll i = 1; i <= n; i++) sz[i] = subTreeSize[traverse[i]];
        for (ll i = 1; i <= n; i++) indx[traverse[i]] = i;

        curr = 2;
        for (auto &u : qq) {
            if (u[0] == 1) {
                ll value = query(1, 1, n, indx[curr], indx[curr]);
                update(1, 1, n, indx[curr], indx[curr]+sz[indx[curr]]-1, -value);
                curr++;
            }
            else {
                ll v = u[1], x = u[2];
                update(1, 1, n, indx[v], indx[v]+sz[indx[v]]-1, x);
            }
        }

        for (ll i = 1; i <= n; i++) cout << query(1, 1, n, indx[i], indx[i]) << " ";
        cout << "\n";

        for (ll i = 1; i <= 3*n; i++) tree[i].sum = tree[i].prop = 0;
    }
}
