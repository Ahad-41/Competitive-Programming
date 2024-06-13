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
    ll n; cin >> n;

    vi adjList[n+1];
    map<Pair, ll> cnt;

    for (ll i = 1; i <= n; i++) {
        ll a, b, c; cin >> a >> b >> c;
        cnt[{a, b}] = c;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    ll clockWise = 0, currNode = 1, nextNode = adjList[1][0];
    for (ll i = 1; i <= n; i++) {
        if (cnt.find({currNode, nextNode}) == cnt.end()) clockWise += cnt[{nextNode, currNode}];

        if (adjList[nextNode][0] == currNode) {
            currNode = nextNode;
            nextNode = adjList[nextNode][1];
        }
        else {
            currNode = nextNode;
            nextNode = adjList[nextNode][0];
        }
    }

    ll antiClockWise = 0;
    currNode = 1, nextNode = adjList[1][1];
    for (ll i = 1; i <= n; i++) {
        if (cnt.find({currNode, nextNode}) == cnt.end()) antiClockWise += cnt[{nextNode, currNode}];

        if (adjList[nextNode][0] == currNode) {
            currNode = nextNode;
            nextNode = adjList[nextNode][1];
        }
        else {
            currNode = nextNode;
            nextNode = adjList[nextNode][0];
        }
    }


    cout << min(clockWise, antiClockWise) << endl;
}
