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
    ll n, m; cin >> n >> m;

    //brtue force approche

    // ll sum = 0;
    // ll sign = -1, start = 1, end = m;
    // ll limit = n/m;

    // for(ll i = 1; i <= limit; i++){
    //     ll value = ((end*(end+1))/2) - (((start-1)*start)/2);
    //     start = end+1;
    //     end = end + m;
        
    //     if(sign == -1){
    //         sum -= value;
    //         sign = 1;
    //     }
    //     else{
    //         sum += value;
    //         sign = -1;
    //     }
    // }

    cout << (n/2) * m << endl;
}
