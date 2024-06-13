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

vector<string> v;
ll cnt, c, r;
bool visited[30][30];

void dfs(ll i, ll j) {
    if (i < 0 || i >= r || j < 0 || j >= c || v[i][j] == '#' || visited[i][j]) return;
    cnt++;
    visited[i][j] = true;
    dfs(i, j+1);
    dfs(i, j-1);
    dfs(i+1, j);
    dfs(i-1, j);
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
    cnt = 0;
    v.clear();
    memset(visited, false, sizeof(visited));

    cin >> c >> r;
    for (ll i = 1; i <= r; i++) {
        string s; cin >> s;
        v.push_back(s);
    }
    
    for (ll i = 0; i < r; i++) {
        for (ll j = 0; j < c; j++) {
            if (v[i][j] == '@') {
                dfs(i, j);
                break;
            }
        }
    }

    cout << cnt << endl;
}
