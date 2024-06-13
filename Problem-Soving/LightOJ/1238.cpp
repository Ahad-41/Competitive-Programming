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

string s[20];
ll m, n, cnt, dist[20][20];
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};

void bfs(ll hx, ll hy) {
    memset(dist, 0, sizeof(dist));
    bool visited[20][20];
    memset(visited, false, sizeof(visited));
    dist[hx][hy] = 0;
    visited[hx][hy] = true;

    queue<Pair> q;
    q.push({hx, hy});

    while (!q.empty()) {
        ll currX = q.front().first, currY = q.front().second;
        q.pop();

        for (ll i = 0; i < 4; i++) {
            ll x = currX + dx[i];
            ll y = currY + dy[i];
            if (x >= m || x < 0 || y >= n || y < 0 || s[x][y] == '#' || s[x][y] == 'm' || visited[x][y]) continue;
            dist[x][y] = dist[currX][currY] + 1;
            visited[x][y] = true;
            q.push({x, y});
        }
    } 
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
    cin >> m >> n;
    ll hx, hy;
    for (ll i = 0; i < m; i++) {
        cin >> s[i];
        for (ll j = 0; j < n; j++) {
            if (s[i][j] == 'h') hx = i, hy = j;
        }
    }

    bfs(hx, hy);

    ll mx = 0;
    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
            if (s[i][j] == 'a' || s[i][j] == 'b' || s[i][j] == 'c') {
                mx = max(mx, dist[i][j]);
            }   
        }
    }
    
    cout << mx << endl;
}
