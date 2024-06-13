#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
int tree[N];

int query(int index) {
    int sum = 0;
    while (index) {
        sum += tree[index];
        index -= index & (-index); 
    }
    return sum;
}

void update(int index, int value, int n) {
    while (index <= n) {
        tree[index] += value;
        index += index & (-index);
    }
}


int main()
{
    int n, q; cin >> n >> q;

    int arr[n];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        update(i, arr[i], n);
    }

    while (q--) {
        
    }
       
}
