const ll N = 2e5+7;
vector <ll> adjList[N];
bool visited[N];

void bfs (ll rootNode) {
    queue <ll> q;
    q.push(rootNode);
    visited[rootNode] = true;

    while (!q.empty()) {
        ll currNode = q.front();
        q.pop();

        for (auto &u : adjList[currNode]) {
            if (visited[u] == false) {
                q.push(u);
                visited[u] = true;
            }
        }
    }
}
