#include <bits/stdc++.h>
using namespace std;
typedef int ll;
void answer();

struct node {
    bool endmark = false;
    ll count = 0;    
    node *child[4] = {NULL};
}; 

node *rootNode;
ll ans;

ll getIndx(char ch){ 
    if (ch == 'A') return 0; 
    if (ch == 'C') return 1; 
    if (ch == 'G') return 2; 
    return 3;
}

void insert(string s){
    node *currNode = rootNode;
    ll n = s.size();
    for (ll i = 0; i < n; i++) {
        ll indx = getIndx(s[i]);
        if (currNode -> child[indx] == NULL) currNode -> child[indx] = new node;
        
        currNode = currNode -> child[indx];
        currNode -> count++;
        ans = max(ans, (i+1)*currNode->count);
    }
    currNode -> endmark = true;
}

void Delete(node *currNode) {
    for (ll i = 0; i < 4; i++) {
        if (currNode -> child[i] != NULL) {
            Delete(currNode -> child[i]);
        }
    }
    delete(currNode);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1; cin >> tt;

    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ": ";
        answer();
    }

    return 0;
}

void answer() {
    ll n; cin >> n;
    ans = 0;
    rootNode = new node;

    while (n--) {
        string s; cin >> s;
        insert(s);
    }

    cout << ans << "\n";
    Delete(rootNode);
}
