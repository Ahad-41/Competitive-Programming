#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define orderedSet tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
// *s.find_by_order(index), s.order_of_key(value)

typedef int ll;
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

string s[15];
char mxChar;
bool visited[15][15];
ll n;
ll X[4] = {0, 1, 0, -1};
ll Y[4] = {1, 0, -1, 0};

struct node {
    ll x, y, total;
    char ch;
};

void bfs(ll x, ll y) {
    memset(visited, false, sizeof(visited));
    s[x][y] = '.';
    visited[x][y] = true;

    queue<node> q;
    q.push({x, y, 0, 'A'});

    while (!q.empty()) {
        auto currNode = q.front();
        q.pop();
        if (currNode.ch == mxChar) {
            cout << currNode.total << endl;
            return;
        }

        for (ll i = 0; i < 4; i++) {
            ll tempX = currNode.x + X[i];
            ll tempY = currNode.y + Y[i];
            if (tempX < 0 || tempY < 0 || tempX >= n || tempY >= n) continue;
            if (s[tempX][tempY] == '#' || visited[tempX][tempY]) continue;
            if (s[tempX][tempY] >= 'A' and s[tempX][tempY] <= 'Z' and s[tempX][tempY] > currNode.ch + 1) continue;

            node next = {tempX, tempY, currNode.total+1, currNode.ch};
            if (s[tempX][tempY] != '.') {
                next.ch++;
                s[tempX][tempY] = '.';
                memset(visited, false, sizeof(visited));
                while (!q.empty()) q.pop();
                visited[tempX][tempY] = true;
                q.push(next);
                break;
            }
            visited[tempX][tempY] = true;
            q.push(next);
        }
    }

    cout << "Impossible" << endl;
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
    cin >> n;
    mxChar = 'A';
    for (ll i = 0; i < n; i++) {
        cin >> s[i];
        for (auto &u : s[i]) {
            if (u >= 'A' and u <= 'Z') mxChar = max(mxChar, u);
        }
    }
    
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (s[i][j] == 'A') {
                bfs(i, j);
                return;
            }
        }
    }
}
