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

vector<ll> primeDiv[1001];
bool check[1001];

void sieve() {
    for (ll i = 4; i <= 1000; i += 2) primeDiv[i].push_back(2);
    for (ll i = 3; i <= 1000; i += 2) {
        if (check[i] == false) {
            for (ll j = i*2; j <= 1000; j += i) {
                check[j] = true;
                primeDiv[j].push_back(i);
            }
        }
    }
}

int main()
{
    optimize();
    sieve();
    ll t; cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        answer();
    }
}

void answer() {
    ll s, t; cin >> s >> t;
    ll move[1005];
    memset(move, -1, sizeof(move));
    move[s] = 0; 
    
    queue<ll> q;
    q.push(s);
    while (!q.empty()) {
        ll currValue = q.front();
        q.pop();
        if (currValue == t) {
            cout << move[currValue] << endl;
            return;
        }

        for (auto &u : primeDiv[currValue]) {
            ll newValue = currValue + u;
            if (newValue <= t and move[newValue] == -1) {
                q.push(newValue);
                move[newValue] = move[currValue] + 1;
            }
        }
    }

    cout << move[t] << endl;
}
