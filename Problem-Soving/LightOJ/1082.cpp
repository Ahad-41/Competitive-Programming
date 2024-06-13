#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int arr[N], tree[N*3];

void segmentTree(int currNode, int left, int right, int minValue) {
    if (left == right) {
        tree[currNode] = arr[left];
        return;
    } 
    int leftNode = currNode*2, rightNode = currNode*2 + 1;
    int mid = left + (right-left)/2;

    segmentTree(leftNode, left, mid, minValue);
    segmentTree(rightNode, mid+1, right, minValue);
    tree[currNode] = min(tree[leftNode], tree[rightNode]);
}

int query(int currNode, int left, int right, int i, int j, int minValue) {
    if (i > right || j < left) return INT_MAX;
    if (left >= i and right <= j) return min(minValue, tree[currNode]);
    
    int leftNode = currNode*2, rightNode = currNode*2 + 1;
    int mid = left + (right-left)/2;
    int leftMinValue = query(leftNode, left, mid, i, j, minValue);
    int rightMinValue = query(rightNode, mid+1, right, i, j, minValue);

    return min(leftMinValue, rightMinValue);
}

int main()
{
    int t; cin >> t;

    for (int i = 1; i <= t; i++) {
        printf("Case %d:\n", i);
        memset(arr, 0, sizeof(arr));
        memset(tree, 0, sizeof(tree));        

        int n, q; cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        int minValue = *min_element(arr+1, arr+n+1);
        segmentTree(1, 1, n, minValue);

        while (q--) {
            int i, j; cin >> i >> j;
            cout << query(1, 1, n, i, j, INT_MAX) << endl;
        }
    }
}
