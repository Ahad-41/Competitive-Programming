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
        cout << "Case " << i << ":" << endl;
    	answer();
    }    
}  

void answer(){
    ll n, q; cin >> n >> q;
    ll arr[n];
    for(auto &u : arr) cin >> u;
    
    while(q--){
        ll a, b; cin >> a >> b;
        
        int low = lower_bound(arr, arr+n, a) - arr;
        int high = upper_bound(arr, arr+n, b) - arr;
        
        cout << high - low << endl;
    }

}
