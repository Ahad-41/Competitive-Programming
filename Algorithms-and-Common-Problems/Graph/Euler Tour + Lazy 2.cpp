// First type query is to decrease subtree of a by x
// Second type query is to count how many arr[u] > 0 in the subtree of a
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+7;

vector<ll> adjList[N], traverse;
ll timer = 1, arr[N], parent[N], indx[N], subTreeSize[N], newArray[N];

void dfs(ll currNode, ll par) {
    indx[currNode] = timer++;
    traverse.push_back(currNode);
    subTreeSize[currNode] = 1;

    for (auto &u : adjList[currNode]) {
        dfs(u, currNode);
        subTreeSize[currNode] += subTreeSize[u];
    }
}

struct Node {
    ll val = 2e18, oldChef = 0, lazy = 0;
} tree[N*4];

void apply(ll currNode, ll left, ll right, ll x) {
    if (tree[currNode].val >= 2e18) return;
    tree[currNode].val -= x;
    if (left == right) {
        if (tree[currNode].val <= 0 and tree[currNode].oldChef) {
            tree[currNode].val = 2e18;
            tree[currNode].oldChef = 0;
        }
    } 
    else tree[currNode].lazy += x;
}

void push(ll currNode, ll left, ll right) {
    if (tree[currNode].lazy == 0 or left == right) return;
    ll mid = (left + right) / 2;
    apply(currNode*2, left, mid, tree[currNode].lazy);
    apply(currNode*2+1, mid+1, right, tree[currNode].lazy);
    tree[currNode].lazy = 0;
}

void segmentTree(ll currNode, ll left, ll right) {
    if (left == right) {
        tree[currNode].val = newArray[left];
        tree[currNode].oldChef = (newArray[left] < 2e18 and newArray[left] > 0 ? 1 : 0);
        tree[currNode].lazy = 0;
        return;
    }

    ll mid = (left + right)/2;
    ll leftNode = currNode*2, rightNode = currNode*2+1;
    segmentTree(leftNode, left, mid);
    segmentTree(rightNode, mid+1, right);

    tree[currNode].val = min(tree[leftNode].val, tree[rightNode].val);
    tree[currNode].oldChef = tree[leftNode].oldChef + tree[rightNode].oldChef;
    tree[currNode].lazy = 0;
}

void update(ll currNode, ll left, ll right, ll i, ll j, ll x) {
    if (i > right or j < left) return;
    if (i <= left and right <= j) {
        if (tree[currNode].val > x) {
            apply(currNode, left, right, x);
            return;
        }
        if (tree[currNode].oldChef == 0) return;
    }
    if (left == right) {
        if (i <= left and left <= j and tree[currNode].oldChef > 0) {
            tree[currNode].val -= x;
            if (tree[currNode].val <= 0) {
                tree[currNode].val = 2e18;
                tree[currNode].oldChef = 0;
            }
        }
        return;
    }

    push(currNode, left, right);
    ll mid = (left + right)/2;
    ll leftNode = currNode*2, rightNode = currNode*2+1;
    update(currNode*2, left, mid, i, j, x);
    update(currNode*2+1, mid+1, right, i, j, x);

    tree[currNode].val = min(tree[leftNode].val, tree[rightNode].val);
    tree[currNode].oldChef = tree[leftNode].oldChef + tree[rightNode].oldChef;
}

ll query(ll currNode, ll left, ll right, ll i, ll j) {
    if (i > right or j < left) return 0;
    if (i <= left and right <= j) return tree[currNode].oldChef;
    push(currNode, left, right);
    
    ll mid = (left + right)/2;
    ll leftNode = currNode*2, rightNode = currNode*2+1;

    ll leftAns = query(leftNode, left, mid, i, j);
    ll rightAns = query(rightNode, mid+1, right, i, j);
    return leftAns + rightAns;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;

    for (ll i = 1; i <= n; i++) {
        cin >> arr[i] >> parent[i];
        adjList[parent[i]].push_back(i);
    }

    arr[0] = 2e18; 
    dfs(0, -1);
    for (ll i = 1; i <= n+1; i++) newArray[i] = arr[traverse[i-1]];
    
    segmentTree(1, 1, n+1);
    ll q; cin >> q;
    while (q--) {
        ll type; cin >> type;
        if (type == 1) {
            ll a, x; cin >> a >> x;
            update(1, 1, n+1, indx[a]+1, indx[a]+subTreeSize[a]-1, x);
        } 
        else {
            ll a; cin >> a;
            cout << query(1, 1, n+1, indx[a]+1, indx[a]+subTreeSize[a]-1) << "\n";
        }
    }
}
