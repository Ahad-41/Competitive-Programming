#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
void answer();

int main()
{
    optimize(); 
    ll t; cin >> t;
    for(ll i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        answer();
    } 
}  

void answer(){
    string s; cin >> s;
    ll n; cin >> n;
    n = abs(n);

    ll start = (s[0] == '-');
    ll ans = 0;

    for(ll i = start; i < s.size(); i++){
        ans = ans*10 + (s[i] - '0');
        ans %= n;
    }

    cout << (ans ? "not divisible" : "divisible") << endl;
}
