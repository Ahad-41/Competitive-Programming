// generator.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
inline ll gen_random(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

void n_Size_Array() {
    ll n = gen_random(1, 5);
    cout << n << "\n";
    for (ll i = 1; i <= n; i++) cout << gen_random(-2, 2) << " ";
    cout << "\n";
}

void n_Size_Permutation() {
    ll n = gen_random(1, 5);
    cout << n << "\n";
    vector<ll> v;
    for (ll i = 1; i <= n; i++) v.push_back(i);
    shuffle(v.begin(), v.end(), rng);
    for (auto &u : v) cout << u << " ";
    cout << endl;
}

void n_Size_String() {
    ll n = gen_random(1, 10);
    cout << n << "\n";
    
    for (ll i = 1; i <= n; i++) {
        char ch = 'a' + gen_random(0, 25);
        cout << ch;
    }
    cout << endl;
}

void n_Size_String_With_Specific_Character() {
    ll n = gen_random(1, 10);
    cout << n << "\n";
    vector<char> v = {'a', 'x', 'q', 'z'};
    
    for (ll i = 1; i <= n; i++) cout << v[gen_random(0, v.size()-1)];
    cout << endl;
}

void tree_Generate() {
    ll n = gen_random(1, 10);
    cout << n << "\n";

    vector<ll> v;
    for (ll i = 1; i <= n; i++) v.push_back(i);
    shuffle(v.begin(), v.end(), rng);

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

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    freopen("input.txt", "w", stdout);
    
    // n_Size_Array();
    // n_Size_Permutation();
    // n_Size_String();
    // n_Size_String_With_Specific_Character();
    // tree_Generate();
    // graph_Generate();
}


// checker.sh
/* -------------------------------------------

#!/bin/bash
set -e
set -o pipefail

OS="$(uname -s)"
EXT=""
if [[ "OS" == "MINGW"* || "OS" == "CYGWIN"* || "OS" == "MSYS"* ]]; then
    EXT=".exe"
fi

for f in a b generator; do
  [[ f.cpp -nt fEXT ]] && g++ -std=c++17 -O2 f.cpp -o fEXT
done

for ((i = 1; ; i++)); do
    echo "-> Test #i"
    ./generatorEXT "i" > input.txt
    ./aEXT < input.txt > out_a.txt
    ./bEXT < input.txt > out_b.txt

    if ! diff -w out_a.txt out_b.txt > /dev/null; then
        echo "** Mismatch at test i"
        echo "Input:"
        cat input.txt
        echo "Output A:"
        cat out_a.txt
        echo "Output B:"
        cat out_b.txt
        break
    fi
done
----------------------------------------- */
