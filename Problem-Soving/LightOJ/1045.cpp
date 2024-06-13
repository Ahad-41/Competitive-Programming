#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
void answer();
ll N = 1e6+1;
vector <double> hsh(N);

int main()
{
    optimize();
    for(ll i = 1; i <= N; i++) hsh[i] = log(i) + hsh[i-1];

    ll t; cin >> t;
    for(ll i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        answer();
    } 
}  

void answer(){
    ll n, b; cin >> n >> b;
    
    ll ans = (hsh[n]/log(b)) + 1;
    cout << ans << endl;
}
