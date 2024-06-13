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
        cout << "Case " << i << ": " << endl;
        answer();
    } 
}  

void answer(){
    ll n, m; cin >> n >> m;
    vector <ll> v(n);
    for(auto &u : v) cin >> u;

    while(m--){
        char ch; cin >> ch;
        if(ch == 'S'){
            ll d; cin >> d;
            for(auto &u : v) u += d;
        }
        else if(ch == 'M'){
            ll d; cin >> d;
            for(auto &u : v) u *= d;
        }
        else if(ch == 'D'){
            ll k; cin >> k;
            for(auto &u : v) u /= k;
        }
        else if(ch == 'P'){
            ll y, z; cin >> y >> z;
            swap(v[y], v[z]);
        }
        else reverse(all(v));
    }    

    for(ll i = 0; i < n-1; i++) cout << v[i] << " ";
    cout << v[n-1] << endl;
}
