#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M = 998244353;
const ll N = 5e6+7;
const ll NN = 5e5+7;
ll spf[N], pwr[NN], col[NN];
bool check[N];
vector<ll> adjList[NN];

void sieve() {
    for (ll i = 2; i < N; i += 2) spf[i] = 2;
    for (ll i = 3; i < N; i += 2) {
        if (!check[i]) {
            spf[i] = i;                       
            for (ll j = i; j*i < N; j += 2) {
                if (!check[j*i]) {
                    spf[j*i] = i;
                    check[j*i] = true;
                } 
            }
        }
    }
}

unordered_map<ll, ll> primeFact(ll n) {
    unordered_map<ll, ll> cnt;
    while (n > 1) {
        cnt[spf[n]] = 1;
        n = n/spf[n];
    }
    return cnt;
}

bool visited[NN];
void dfs(ll currNode) {
    if (visited[currNode]) return;
    visited[currNode] = 1;
    for (auto &u : adjList[currNode]) dfs(u);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tt = 1; cin >> tt;
    sieve();

    pwr[0] = 1;
    for (ll i = 1; i < NN; i++) pwr[i] = (pwr[i-1] * 2) % M;

    test:
    while (tt--) {
        ll n; cin >> n;

        ll arr[n+1];
        unordered_map<ll, vector<ll>> cnt;
        ll one = 0;

        for (ll i = 1; i <= n; i++) {
            cin >> arr[i];
            auto it = primeFact(arr[i]);
            for (auto &u : it) cnt[u.first].push_back(i);
        }

        for (auto &u : cnt) {
            if (u.second.size() > 2) {
                cout << "0\n";
                goto test;
            }
        }

        for (ll i = 1; i <= n; i++) {
            visited[i] = 0;
            adjList[i].clear();
            col[i] = 0;
        }
        
        for (auto &u : cnt) {
            if (u.second.size() == 2) {
                adjList[u.second[0]].push_back(u.second[1]);
                adjList[u.second[1]].push_back(u.second[0]);
            } 
            else one++;
        }

        for (ll i = 1; i <= n; i++) {
            if (visited[i]) continue;
            queue<ll> q;
            q.push(i);
            visited[i] = col[i] = 1;
            while (!q.empty()) {
                auto it = q.front();
                q.pop();
                
                for (auto &u : adjList[it]) {
                    if (visited[u] and col[u] == col[it]) {
                        cout << "0\n";
                        goto test;
                    }
                    if (visited[u]) continue;
                    q.push(u);
                    visited[u] = 1;
                    col[u] = (col[it] == 1 ? 2 : 1);
                }
            }
        }

        if (one == cnt.size()) {
            cout << (pwr[n]-2 + M) % M << "\n";
            goto test;
        }

        for (ll i = 1; i <= n; i++)  visited[i] = 0;
        ll cc = 0;
        for (ll i = 1; i <= n; i++) {
            if (visited[i]) continue;
            cc++;
            dfs(i);
        }

        cout << pwr[cc] << "\n";           
    }
}
