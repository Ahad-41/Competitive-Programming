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

string s[500];
ll total[500][500], m, n, q;
bool visited[500][500];

bool alright(ll i, ll j) {
    return(i >= 0 and i < m and j >= 0 and j < n and !visited[i][j] and s[i][j] != '#');
}

ll dfs(ll x, ll y) {
    if (alright(x, y) == false) return 0;

    visited[x][y] = true;
    ll cnt = (s[x][y] == 'C');

    cnt += dfs(x, y+1);
    cnt += dfs(x, y-1);
    cnt += dfs(x+1, y);
    cnt += dfs(x-1, y);

    return cnt;
}

int main()
{
    optimize();
    ll t; cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ":" << endl;
        answer();
    }
}

void answer() {
    cin >> m >> n >> q;
    for (ll i = 0; i < m; i++) cin >> s[i];

    for (auto &u : total) for (auto &v : u) v = -1;

    while (q--) {
        ll x, y; cin >> x >> y;
        x--, y--;
        if (total[x][y] != -1) cout << total[x][y] << endl;

        else {
            memset(visited, false, sizeof(visited));
            ll temp = dfs(x, y);
            cout << temp << endl;

            for (ll i = 0; i < m; i++) {
                for (ll j = 0; j < n; j++) {
                    if (visited[i][j]) total[i][j] = temp;
                }
            }
        }
    }

}
