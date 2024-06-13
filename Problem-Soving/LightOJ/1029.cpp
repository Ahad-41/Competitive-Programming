#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define Pair pair<ll, ll> 
void answer();

const ll N = 105;
vector<pair<ll, ll>> adjList[N];
bool alreadyTaken[N];

ll mst1(ll currNode) {
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.push({0, currNode});
    ll minCost = 0;

    while (!pq.empty()) {
        ll cost = pq.top().first;
        currNode = pq.top().second;
        pq.pop();
        if (alreadyTaken[currNode] == true) continue;
        
        minCost += cost;
        alreadyTaken[currNode] = true;
        
        for (auto &u : adjList[currNode]) {
            if (alreadyTaken[u.first] == false) {
                pq.push({u.second, u.first});
            }
        }         
    } 

    return minCost;
}

ll mst2(ll currNode) {
    priority_queue<Pair> pq;
    pq.push({0, currNode});
    ll maxCost = 0;

    while (!pq.empty()) {
        ll cost = pq.top().first;
        currNode = pq.top().second;
        pq.pop();
        if (alreadyTaken[currNode] == true) continue;
        
        maxCost += cost;
        alreadyTaken[currNode] = true;
        
        for (auto &u : adjList[currNode]) {
            if (alreadyTaken[u.first] == false) {
                pq.push({u.second, u.first});
            }
        }         
    } 

    return maxCost;
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
    ll n; cin >> n;
    for (ll i = 0; i <= n; i++) adjList[i].clear();
    
    while (1) {
        ll u, v, w; cin >> u >> v >> w;
        if (!u and !v and !w) break;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    memset(alreadyTaken, false, sizeof(alreadyTaken));
    ll total = mst1(0);
    memset(alreadyTaken, false, sizeof(alreadyTaken));
    total += mst2(0);

    if (total & 1) cout << total << "/2" << endl;
    else cout << total / 2 << endl;
}
