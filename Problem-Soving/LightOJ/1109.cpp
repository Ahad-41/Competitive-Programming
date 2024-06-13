#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
void answer();

int main()
{
    optimize();
    vector <pair<ll, ll> > v;
    for(ll i = 1; i <= 1000; i++){
        ll cnt = 0;
        for(ll j = 1; j*j <= i; j++){
            if(i % j == 0){
                if(j*j == i) cnt++;
                else cnt += 2;
            }
        }
        v.push_back({cnt, -i});
    }

    sort(all(v));
    vector <ll> ans;
    for(auto &u : v) ans.push_back(-u.second);
    
    ll t; cin >> t;
    for(ll i = 1; i <= t; i++){
        ll n; cin >> n;
        cout << "Case " << i << ": " << ans[n-1] << endl;;
    } 
}  
