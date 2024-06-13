#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main()
{
    int n, a, b; cin >> n >> a >> b;
    
    ll arr[n+1] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    
    ll maxSum = -1e18;
    multiset <ll> s;

    for (int i = a; i <= n; i++) {
        if (i > b) s.erase(s.find(arr[i-b-1]));
        s.insert(arr[i-a]);
        maxSum = max(maxSum, arr[i] - *s.begin());
    }
    
    cout << maxSum << '\n';
}  
