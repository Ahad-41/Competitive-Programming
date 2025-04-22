#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    ll cnt = 0;
    node *child[2] = {NULL};    
}; 
node *rootNode;

void insert(ll n){
    node *currNode = rootNode;
    for (ll i = 30; i >= 0; i--) {
        ll indx = (n >> i) & 1;
        if (currNode -> child[indx] == NULL) currNode -> child[indx] = new node;
        currNode -> cnt++;
        currNode = currNode -> child[indx];
    }
    currNode -> cnt++;
}

void erase(ll n){
    node *currNode = rootNode;
    for (ll i = 30; i >= 0; i--) {
        ll indx = (n >> i) & 1;
        currNode -> cnt--;
        currNode = currNode -> child[indx];
    }
    currNode -> cnt--;
}

ll search(ll n){
    node *currNode = rootNode;
    ll ans = 0;
    for (ll i = 30; i >= 0; i--) {
        ll indx = (n >> i) & 1;
        ll ulta = !indx;
        if (currNode->child[ulta] != NULL and currNode->child[ulta]->cnt) {
            ans += (1LL << i);
            currNode = currNode->child[ulta];
        }
        else currNode = currNode->child[indx];
    }
    return ans;
}

void Delete(node *currNode) {
    for (ll i = 0; i < 2; i++) if (currNode -> child[i] != NULL) Delete(currNode -> child[i]);
    delete(currNode);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll n; cin >> n;
    ll arr[n];
    for (auto &u : arr) cin >> u;

    rootNode = new node;
    insert(0);
    
    ll mxXor = 0, currXor = 0;
    for (auto &u : arr) {
        currXor ^= u;
        mxXor = max(mxXor, search(currXor));
        insert(currXor);
    }
    
    cout << mxXor << "\n";
    Delete(rootNode);
}   
