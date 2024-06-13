#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    optimize();

    int n; cin >> n;
    int arr[n];
    for(auto &u : arr) cin >> u;

    /* Time Complexity -> O(n^3)

    int maxSum = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int tempSum = 0;
            for(int k = i; k <= j; k++){
                tempSum += arr[k];
            }
            maxSum = max(maxSum, tempSum);
        }
    }
    */

    /* Time Complexity -> O(n^2)

    int maxSum = 0;
    for(int i = 0; i < n; i++){
        int tempSum = 0;
        for(int j = i; j < n; j++){
            tempSum += arr[j];
            maxSum = max(maxSum, tempSum);
        }
    }
    */

    /* Time Complexity -> O(n)

    int maxSum = 0, tempSum = 0;
    for(int i = 0; i < n; i++){
        tempSum = max(arr[i], tempSum+arr[i]);
        maxSum = max(maxSum, tempSum);
    }
    */

    cout << maxSum << endl;
}  
