#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define orderedSet tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_n_update>
// *s.find_by_order(index), s.order_of_key(value)

typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> Pair;
typedef vector<Pair> vp;

#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define M 1000000007
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a*b / gcd(a, b)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
void answer();

struct info {
    ll u, v, w;
};

vector<Pair> adjList[5005];

vector<ll> dijkstra(ll source, ll n) {
    vector<ll> cost(n+1);
    for (ll i = 0; i <= n; i++) cost[i] = 1e18;
    cost[source] = 0;

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        ll currNode = pq.top().second;
        ll currNodeCost = pq.top().first;
        pq.pop();
        
        if (currNodeCost > cost[currNode]) continue;

        for (auto &u : adjList[currNode]) {
            // Relaxation
            if (cost[u.first] > currNodeCost + u.second) {
                cost[u.first] = currNodeCost + u.second;
                pq.push({cost[u.first], u.first});
            }
        }
    }

    return cost;
}

int main()
{
    optimize();
    ll t; cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        answer();
    }
}

void answer() {
    for (auto &u : adjList) u.clear();
    ll n, e; cin >> n >> e;

    vector<info> edge;
    while (e--) {
        ll u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
        edge.push_back({u, v, w});
    }

    vector<ll> fromSource = dijkstra(1, n);
    vector<ll> fromDestination = dijkstra(n, n);
    
    set<ll> s;
    for (auto &curr : edge) {
        ll cost = fromSource[curr.u] + fromDestination[curr.v];
        
        s.insert(cost + (curr.w * 3));
        s.insert(cost + curr.w);

        cost = fromSource[curr.v] + fromDestination[curr.u];
        s.insert(cost + (curr.w * 3));
        s.insert(cost + curr.w);
    }

    s.erase(s.begin());
    cout << *s.begin() << endl;
}
