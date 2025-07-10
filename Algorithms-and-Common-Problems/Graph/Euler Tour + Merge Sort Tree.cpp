// https://toph.co/arena?practice=686e41a69d511ccfa58fdc0a#!/p/6863ca4db4ab47db2729d4e6
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5+7;
vector<ll> adjList[N], traverse;
ll arr[N], parent[N], indx[N], subTreeSize[N], sz[N], newArray[N];

void dfs(ll currNode) {
    subTreeSize[currNode] = 1;
    traverse.push_back(currNode);
    for (auto &u : adjList[currNode]) {
        if (u == parent[currNode]) continue;
        dfs(u);
        subTreeSize[currNode] += subTreeSize[u];
    }
}

vector<ll> tree[N*4];
void segmentTree(ll currNode, ll left, ll right) {
    tree[currNode].clear();
    if (left == right) {
        tree[currNode].push_back(newArray[left]);
        return;
    } 
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;

    segmentTree(leftNode, left, mid);
    segmentTree(rightNode, mid+1, right);

    ll i = 0, j = 0;
    while (i < tree[leftNode].size() and j < tree[rightNode].size()) {
        if (tree[leftNode][i] <= tree[rightNode][j]) tree[currNode].push_back(tree[leftNode][i++]);
        else tree[currNode].push_back(tree[rightNode][j++]);
    }
    while (i < tree[leftNode].size()) tree[currNode].push_back(tree[leftNode][i++]);
    while (j < tree[rightNode].size()) tree[currNode].push_back(tree[rightNode][j++]);
}

// return the number of element from i-th index to j-th index which is less than k ->
ll query1(ll currNode, ll left, ll right, ll i, ll j, ll k) {
    if (i > right || j < left) return 0;
    if (left >= i and right <= j) {
        ll less = upper_bound(tree[currNode].begin(), tree[currNode].end(), k-1) - tree[currNode].begin();
        return less;
    }
    
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    ll leftCnt = query1(leftNode, left, mid, i, j, k);
    ll rightCnt = query1(rightNode, mid+1, right, i, j, k);

    return leftCnt+rightCnt;
}

// return the number of element from i-th index to j-th index which is boro than k ->
ll query2(ll currNode, ll left, ll right, ll i, ll j, ll k) {
    if (i > right || j < left) return 0;
    if (left >= i and right <= j) {
        ll lessEqual = upper_bound(tree[currNode].begin(), tree[currNode].end(), k) - tree[currNode].begin();
        ll boro = (right-left+1) - lessEqual;
        return boro;
    }
    
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    ll leftCnt = query2(leftNode, left, mid, i, j, k);
    ll rightCnt = query2(rightNode, mid+1, right, i, j, k);

    return leftCnt+rightCnt;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ll tt; cin >> tt;

    test:
    while (tt--) {
        ll n; cin >> n;
        for (ll i = 1; i <= n; i++) adjList[i].clear();
        
        parent[1] = -1;
        for (ll i = 2; i <= n; i++) {
            cin >> parent[i];
            adjList[parent[i]].push_back(i);
            adjList[i].push_back(parent[i]);
        }

        for (ll i = 1; i <= n; i++) cin >> arr[i];

        traverse.clear();
        traverse.push_back(0);
        dfs(1);

        for (ll i = 1; i <= n; i++) sz[i] = subTreeSize[traverse[i]];
        for (ll i = 1; i <= n; i++) newArray[i] = arr[traverse[i]];
        for (ll i = 1; i <= n; i++) indx[traverse[i]] = i;
        // ---------------------------------------------------------
        // for (ll i = 1; i <= n; i++) cout << traverse[i] << " ";
        // cout << endl;

        // for (ll i = 1; i <= n; i++) cout << sz[i] << " ";
        // cout << endl;
        
        // for (ll i = 1; i <= n; i++) cout << newArray[i] << " ";
        // cout << endl;

        // for (ll i = 1; i <= n; i++) cout << indx[i] << " ";
        // cout << endl;
        // --------------------------------------------------------

        segmentTree(1, 1, n);
        
        ll ans = 0;
        for (ll i = 1; i <= n; i++) {
            for (auto &u : adjList[i]) {
                if (u == parent[i]) {
                    ll choto = query1(1, 1, n, indx[i], indx[i]+sz[indx[i]]-1, arr[i]);
                    ll boro = query2(1, 1, n, 1, n, arr[i]) - query2(1, 1, n, indx[i], indx[i]+sz[indx[i]]-1, arr[i]);
                    ans += boro*choto;
                }
                else {
                    ll boro = query2(1, 1, n, indx[u], indx[u]+sz[indx[u]]-1, arr[i]);
                    ll choto = query1(1, 1, n, 1, n, arr[i]) - query1(1, 1, n, indx[u], indx[u]+sz[indx[u]]-1, arr[i]);
                    ans += boro*choto;
                }
            }
        }

        cout << ans << "\n";
    }
}
