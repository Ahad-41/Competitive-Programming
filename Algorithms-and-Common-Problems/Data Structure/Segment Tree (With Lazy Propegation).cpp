#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int arr[N];

struct info {
    long long int prop, sum;
} tree[N*3];


// create segment tree ->
void segmentTree(int currNode, int left, int right) {
    if (left == right) {
        tree[currNode].sum = arr[left];
        return;
    } 
    
    int leftNode = currNode*2, rightNode = currNode*2 + 1;
    int mid = left + (right-left)/2;
    segmentTree(leftNode, left, mid);
    segmentTree(rightNode, mid+1, right);

    tree[currNode].sum = tree[leftNode].sum + tree[rightNode].sum;
}

// return the sum of i-th index to j-th index ->
int query(int currNode, int left, int right, int i, int j, int carry = 0) {
    if (i > right || j < left) return 0;
    if (left >= i and right <= j) {
        return tree[currNode].sum + carry * (right - left + 1);
    }
    
    int leftNode = currNode*2, rightNode = currNode*2 + 1;
    int mid = left + (right-left)/2;
    int leftSum = query(leftNode, left, mid, i, j, carry + tree[currNode].prop);
    int rightSum = query(rightNode, mid + 1, right, i, j, carry + tree[currNode].prop);

    return leftSum + rightSum;
}

// update in the i-th index to j-th index with new value -> 
void update(int currNode, int left, int right, int i, int j, int newValue) {
    if (i > right || j < left) return;
    if (left >= i and right <= j) {
        tree[currNode].sum += ((right - left + 1) * newValue);
        tree[currNode].prop += newValue;
        return;
    }

    int leftNode = currNode*2, rightNode = currNode*2 + 1;
    int mid = left + (right-left)/2;
    update(leftNode, left, mid, i, j, newValue);
    update(rightNode, mid+1, right, i, j, newValue);
    
    tree[currNode].sum = tree[leftNode].sum + tree[rightNode].sum + (right - left + 1) * tree[currNode].prop;
}

int main()
{
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    segmentTree(1, 1, n);

    while (q--) {
        
    }
}