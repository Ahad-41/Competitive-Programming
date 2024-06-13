#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
void answer();
ll binaryToDecimal(ll binary);

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
    string s1, s2; cin >> s1 >> s2;
    
    vector <ll> decimal;
    string temp;

    for(ll i = 0; i < s1. size(); i++){
        if(s1[i] == '.'){
            decimal.push_back(stoi(temp));
            temp.clear();
        }
        else temp += s1[i];
    }
    decimal.push_back(stoi(temp));
    temp.clear();

    vector <ll> binary;
    for(ll i = 0; i < s2. size(); i++){
        if(s2[i] == '.'){
            binary.push_back(stoi(temp));
            temp.clear();
        }
        else temp += s2[i];
    }
    binary.push_back(stoi(temp));

    for(auto &u : binary) u = binaryToDecimal(u);

    for(ll i = 0; i < 4; i++){
        if(decimal[i] != binary[i]){
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

ll binaryToDecimal(ll binary){
    ll decimal = 0, a = 1;
    
    while(binary){
        decimal += (binary % 10) * a;
        binary /= 10;
        a *= 2;
    }

    return decimal;
}
