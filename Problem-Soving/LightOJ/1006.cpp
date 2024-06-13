#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
void answer();
ll M = 1e7+7;

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
    vector <ll> v(10001);
    for(ll i = 0; i < 6; i++) cin >> v[i];
    ll n; cin >> n;
    
    for(ll i = 6; i <= n; i++){
        ll sum = 0;
        for(ll j = i-6; j < i; j++) sum += v[j];
        v[i] = sum % M;
    }

    cout << v[n] % M << endl;
}
