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
    ll n, p, q; cin >> n >> p >> q;

    vector <ll> v(n);
    for(auto &u : v) cin >> u;

    ll count = 0, sum = 0;
    for(ll i = 0; i < n; i++){
        sum += v[i];
        if(sum <= q){
            if(count >= p) break;
            else count++;
        }
        else break;
    }

    cout << count << endl;
}
