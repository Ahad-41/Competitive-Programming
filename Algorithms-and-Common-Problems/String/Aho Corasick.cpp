#include <bits/stdc++.h>
using namespace std;

struct AhoCorasick {
    int N, P;
    const int A = 26;
    vector<vector<int>> next;
    vector<int> link, out_link; // out_link[v] = nearest ancestor of v where an input pattern ended which is also a suffix link of v.
    vector<vector<int>> out;
    vector<int> count; // Stores the number of occurrences for each pattern

    AhoCorasick() : N(0), P(0) {
        node();
    }

    int node() {
        next.emplace_back(A, 0);
        link.emplace_back(0);
        out_link.emplace_back(0);
        out.emplace_back(0);
        count.emplace_back(0);
        return N++;
    }

    inline int get(char c) {
        return c - 'a';
    }

    int add_pattern(const string& T) {
        int u = 0;
        for (auto c : T) {
            if (!next[u][get(c)]) next[u][get(c)] = node();
            u = next[u][get(c)];
        }
        out[u].push_back(P);
        count.push_back(0);
        return P++;
    }

    void compute() {
        queue<int> q;
        for (q.push(0); !q.empty(); ) {
            int u = q.front();
            q.pop();
            for (int c = 0; c < A; ++c) {
                int v = next[u][c];
                if (!v) next[u][c] = next[link[u]][c];
                else {
                    link[v] = u ? next[link[u]][c] : 0;
                    out_link[v] = out[link[v]].empty() ? out_link[link[v]] : link[v];
                    q.push(v);
                }
            }
        }
    }

    int advance(int u, char c) {
        while (u && !next[u][get(c)]) u = link[u];
        u = next[u][get(c)];
        return u;
    }

    void match(const string& S) {
        int u = 0;
        for (auto c : S) {
            u = advance(u, c);
            for (int v = u; v; v = out_link[v]) {
                for (auto p : out[v]) count[p]++;
            }
        }
    }

    void print_counts() {
        for (int i = 0; i < P; ++i) {
            cout << count[i] << endl;
        }
    }
};

// Main function
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ":\n";
        int q; cin >> q;

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
