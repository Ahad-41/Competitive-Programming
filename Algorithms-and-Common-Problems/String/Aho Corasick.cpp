#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct AhoCorasick {
    ll N, P;
    const ll A = 26;
    vector<vector<ll>> next;
    vector<ll> link, out_link; // out_link[v] = nearest ancestor of v where an input pattern ended which is also a suffix link of v.
    vector<vector<ll>> out;
    vector<ll> count; // Stores the number of occurrences for each pattern

    AhoCorasick() : N(0), P(0) {
        node();
    }

    ll node() {
        next.emplace_back(A, 0);
        link.emplace_back(0);
        out_link.emplace_back(0);
        out.emplace_back(0);
        count.emplace_back(0);
        return N++;
    }

    inline ll get(char c) {
        return c - 'a';
    }

    ll add_pattern(const string& T) {
        ll u = 0;
        for (auto c : T) {
            if (!next[u][get(c)]) next[u][get(c)] = node();
            u = next[u][get(c)];
        }
        out[u].push_back(P);
        count.push_back(0);
        return P++;
    }

    void compute() {
        queue<ll> q;
        for (q.push(0); !q.empty(); ) {
            ll u = q.front();
            q.pop();
            for (ll c = 0; c < A; ++c) {
                ll v = next[u][c];
                if (!v) next[u][c] = next[link[u]][c];
                else {
                    link[v] = u ? next[link[u]][c] : 0;
                    out_link[v] = out[link[v]].empty() ? out_link[link[v]] : link[v];
                    q.push(v);
                }
            }
        }
    }

    ll advance(ll u, char c) {
        while (u && !next[u][get(c)]) u = link[u];
        u = next[u][get(c)];
        return u;
    }

    void match(const string& S) {
        ll u = 0;
        for (auto c : S) {
            u = advance(u, c);
            for (ll v = u; v; v = out_link[v]) {
                for (auto p : out[v]) count[p]++;
            }
        }
    }

    void print_counts() {
        for (ll i = 0; i < P; i++)  cout << count[i] << "\n";
    }
};

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tc; cin >> tc;

    test:
    while (tc--) {
        ll q; cin >> q;

        string text; cin >> text;
        AhoCorasick ac;

        while (q--) {
            string s; cin >> s;
            ac.add_pattern(s);
        }

        ac.compute();
        ac.match(text);
        ac.print_counts();
    }
}
