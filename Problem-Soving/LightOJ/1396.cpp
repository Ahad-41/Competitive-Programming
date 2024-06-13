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

bool isGreater(string temp, string s) {
    ll n = s.size();
    for (ll i = 0; i < n; i++) {
        if (temp[i] < s[i]) return false;
        if (temp[i] > s[i]) return true;
    }
    return false;
}

int main()
{
    optimize();
    ll t; cin >> t;
    for (ll test = 1; test <= t; test++) {
        cout << "Case " << test << ": ";
        
        string s; cin >> s;
        ll n = s.size();

        bool check = true;
        for (auto &u : s) if (u != '9') check = false; // all 9 check

        if (check) { // all is 9
            cout << 1;
            for(ll i = 1; i < n; i++) cout << 0;
            cout << 1 << endl;
            continue;
        }
        

        // kahini
        string a;
        for (ll i = 0; i < n/2; i++) a += s[i];

        string b = a;
        reverse(all(b));

        string temp = a;
        if (n & 1) temp += s[n/2];
        temp += b;

        if (isGreater(temp, s)) {
            cout << temp << endl;
            continue;
        } 

        for (ll i = (n-1)/2; i >= 0; i--) {
            if (temp[i] != '9') {
                temp[i]++;
                temp[n-i-1] = temp[i];
                for (ll j = i+1; j < n-i-1; j++) temp[j] = '0';
                break;
            }
        }    

        cout << temp << endl;
    }
}
