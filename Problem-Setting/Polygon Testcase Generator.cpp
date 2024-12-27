#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gen_random(ll l, ll r) {
    return rnd.next(l, r);
}

void n_Size_Array() {
    ll n = gen_random(1, 5);
    cout << n << "\n";
    for (ll i = 1; i <= n; i++) {
        cout << gen_random(1, 1000);
        if (i < n) cout << " ";
    }
    cout << "\n";
}

void n_Size_Permutation() {
    ll n = gen_random(1, 20);
    cout << n << "\n";
    vector<ll> v;
    for (ll i = 1; i <= n; i++) v.push_back(i);
    shuffle(v.begin(), v.end());

    ll m = v.size();
    for (ll i = 0; i < m; i++) {
        cout << v[i];
        if (i != m-1) cout << " ";
    }
    cout << "\n";
}

void n_Size_String() {
    ll n = gen_random(1, 10);
    cout << n << "\n";
    
    for (ll i = 1; i <= n; i++) {
        char ch = 'a' + gen_random(0, 25);
        cout << ch;
    }
    cout << "\n";
}

void n_Size_String_With_Specific_Character() {
    ll n = gen_random(1, 10);
    cout << n << "\n";
    vector<char> v = {'a', 'x', 'q', 'z'};
    
    for (ll i = 1; i <= n; i++) cout << v[gen_random(0, v.size()-1)];
    cout << "\n";
}

void tree_Generate() {
    ll n = gen_random(1, 10);
    cout << n << "\n";

    vector<ll> v;
    for (ll i = 1; i <= n; i++) v.push_back(i);
    shuffle(v.begin(), v.end());

    for (ll i = 1; i < n; i++) {
        ll indx = gen_random(0, i-1);
        cout << v[indx] << " " << v[i] << "\n";
    }
}

void graph_Generate() {
    ll n = gen_random(1, 10);
    ll m = gen_random(1, n*(n-1)/2-1);
    cout << n << " " << m << "\n";

    set<pair<ll, ll>> st;
    while (st.size() < m) {
        ll u = gen_random(1, n);
        ll v = gen_random(1, n);
        if (u == v) continue;
        st.insert({min(u, v), max(u, v)});
    }

    for (auto &u : st) cout << u.first << " " << u.second << "\n";
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    // n_Size_Array();
    // n_Size_Permutation();
    // n_Size_String();
    // n_Size_String_With_Specific_Character();
    // tree_Generate();
    // graph_Generate();
}

/*

<#list 1..10 as s>
    Generator_Small  ${s} > $
</#list>

*/
