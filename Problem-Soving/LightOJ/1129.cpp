#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
void answer();

struct node {
    bool endmark = false;
    node *child[10] = {NULL};    
}; 
node *rootNode;

ll getIndx(char ch) {return ch - '0'; }

void insert(string s){
    node *currNode = rootNode;
    for (auto &u : s) {
        ll indx = getIndx(u);
        if (currNode -> child[indx] == NULL) {
            currNode -> child[indx] = new node;
        }    
        currNode = currNode -> child[indx];
    }
    currNode -> endmark = true;
}

bool search(string s) {
    node *currNode = rootNode;
    for (auto &u : s) {
        ll indx = getIndx(u);
        currNode = currNode -> child[indx];
    }
    for (ll i = 0; i < 10; i++) if (currNode -> child[i] != NULL) return true;
    return false;
}

void Delete(node *currNode) {
    for (ll i = 0; i < 10; i++) {
        if (currNode -> child[i] != NULL) {
            Delete(currNode -> child[i]);
        }
    }
    delete(currNode);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ": ";
        answer();
    }

    return 0;
}

void answer() {
    rootNode = new node;
    ll n; cin >> n;
    string arr[n];
    for (auto &u : arr) {
        cin >> u;
        insert(u);
    }

    for (auto &u : arr) {
        if (search(u) == true) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    Delete(rootNode);
}
