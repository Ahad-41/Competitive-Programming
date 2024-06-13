#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
void answer();

const int N = 20005;
vector <int> adjList[N];
bool visited[N], opponentTeam[N];

ll bfs (int rootNode) {
    queue <int> q;
    q.push(rootNode);
    visited[rootNode] = true;
    opponentTeam[rootNode] = true;
    
    ll my = 0, opponent = 1;
    while (q.empty() == false) {
        int currNode = q.front();
        q.pop();
        
        for (auto &u : adjList[currNode]){
            if(visited[u] == false){
                q.push(u);
                visited[u] = true;

                if(opponentTeam[currNode] == true) my++;
                else{
                    opponent++;
                    opponentTeam[u] = true;
                }
            }
        }
    }

    return max(my, opponent);
}

int main() {
    optimize();
    ll t; cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        memset(visited, false, sizeof(visited));
        memset(opponentTeam, false, sizeof(opponentTeam));
        for (int i = 0; i < N; i++) adjList[i].clear();

        answer();
    }
}

void answer() {
    int n; cin >> n;
    while (n--) {
        int u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    ll maxMember = 0;
    for (int i = 1; i <= 20000; i++) {
        if (visited[i] == false and adjList[i].empty() == false) {
            maxMember += bfs(i);
        }
    }

    cout << maxMember << endl;
}
