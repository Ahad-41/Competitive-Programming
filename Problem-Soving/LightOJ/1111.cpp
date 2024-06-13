#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define orderedSet tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
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

const ll N = 1005;
ll k, n, m, numberOfTime[N];
bool visited[N];
vi adjList[N];

void dfs(ll currNode) {
    if (visited[currNode]) return;
    visited[currNode] = true;
    numberOfTime[currNode]++;
    
    for (auto &u : adjList[currNode]) dfs(u);
}

int main()
{
    optimize();
    ll t; cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i<< ": ";
        answer();
    }
}

void answer() {
    cin >> k >> n >> m;
    for (ll i = 1; i <= n; i++) {
        numberOfTime[i] = 0;
        adjList[i].clear();
    }

    ll arr[k];
    for (auto &u : arr) cin >> u;

    for (ll i = 1; i <= m; i++) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
    }

    for (auto &u : arr) {
        memset(visited, false, sizeof(visited));
        dfs(u);
    }
    
    ll count = 0;
    for (ll i = 1; i <= n; i++) {
        if (numberOfTime[i] == k) count++;
    }

    cout << count << endl;
}
