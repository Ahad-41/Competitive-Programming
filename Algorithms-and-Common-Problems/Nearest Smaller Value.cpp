// https://cses.fi/problemset/task/1645/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n; cin >> n;
    ll arr[n];
    for (auto &u : arr) cin >> u;
 
    stack <ll> st;
    ll solution[n];
    
    for (ll i = n-1; i >= 0; i--) {
        if (st.empty() || arr[st.top()] <= arr[i]) st.push(i);
        else {
            while (!st.empty() and arr[st.top()] > arr[i]) {
                solution[st.top()] = i+1;
                st.pop();
            }
            st.push(i);
        }
    }
 
    for (ll i = 0; i < n; i++) cout << solution[i] << " \n"[i==n-1];
}
