#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int arr[N], tree[N*3];

void segmentTree(int currNode, int left, int right) {
    if (left == right) {
        tree[currNode] = arr[left];
        return;
    } 
    int leftNode = currNode*2 + 1, rightNode = currNode*2 + 2;
    int mid = left + (right-left)/2;

    segmentTree(leftNode, left, mid);
    segmentTree(rightNode, mid+1, right);
    tree[currNode] = tree[leftNode] + tree[rightNode];
}

int query(int currNode, int left, int right, int i, int j) {
    if (i > right || j < left) return 0;
    if (left >= i and right <= j) return tree[currNode];
    
    int leftNode = currNode*2 + 1, rightNode = currNode*2 + 2;
    int mid = left + (right-left)/2;
    int leftSum = query(leftNode, left, mid, i, j);
    int rightSum = query(rightNode, mid+1, right, i, j);

    return leftSum + rightSum;
}

void update(int currNode, int left, int right, int i, int newValue) {
    if (i > right || i < left) return;
    if (left == right) {
        tree[currNode] += newValue;
        return;
    }

    int leftNode = currNode*2 + 1, rightNode = currNode*2 + 2;
    int mid = left + (right-left)/2;

    update(leftNode, left, mid, i, newValue);
    update(rightNode, mid+1, right, i, newValue);
    tree[currNode] = tree[leftNode] + tree[rightNode];
}

int main()
{
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case %d:\n", i);
        memset(tree, 0, sizeof(tree));
        memset(arr, 0, sizeof(arr));

        int n, q; cin >> n >> q;
        for (int j = 0; j < n; j++) cin >> arr[j];
        segmentTree(0, 0, n-1);

        while (q--) {
            int type; cin >> type;
            if (type == 1) {
                int index; cin >> index;
                
                int value = query(0, 0, n - 1, index, index);
                cout << value << endl;

                update(0, 0, n-1, index, -value);
            }
            else if (type == 2) {
                int index, value; cin >> index >> value;
                update(0, 0, n-1, index, value);
            }
            else {
                int a, b; cin >> a >> b;
                cout << query(0, 0, n-1, a, b) << endl;
            }
        }
    }
}
