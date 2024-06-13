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
    ll n; cin >> n;
    string s = to_string(n);

    for(ll i = 0; i < s.size(); i++){
        if(s[i] != s[s.size()-i-1]){
            cout << "No" << endl;
            return;
        }
    }
    
    cout << "Yes" << endl;
}
