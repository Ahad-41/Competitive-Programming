#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node {
    bool endmark = false;
    node *child[52] = {NULL};    
}; 
node *rootNode;

ll getIndx(char ch){
    ll indx = ch - 'A';
    if (ch >= 'a') indx -= 6;
    return indx;
}

void insert(string s){
    node *currNode = rootNode;
    for (auto &u : s) {
        ll indx = getIndx(u);
        if (currNode -> child[indx] == NULL) {
            currNode -> child[indx] = new node;
        }    
        currNode = currNode -> child[indx];
    }
    currNode -> endmark = true;
}

bool search(string s){
    node *currNode = rootNode;
    for (auto &u : s) {
        ll indx = getIndx(u);
        if (currNode -> child[indx] == NULL) return false;
        currNode = currNode -> child[indx];
    }
    return currNode -> endmark;
}

void Delete(node *currNode) {
    for (ll i = 0; i < 52; i++) {
        if (currNode -> child[i] != NULL) {
            Delete(currNode -> child[i]);
        }
    }
    delete(currNode);
}

int main()
{
    rootNode = new node;
}