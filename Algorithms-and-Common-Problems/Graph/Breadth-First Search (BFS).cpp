const ll N = 1e5+7;
vector <ll> adjList[N];
bool visited[N];

void bfs (int rootNode) {
    queue <int> q;
    q.push(rootNode);
    visited[rootNode] = true;

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();

        for (auto &u : adjList[currNode]) {
            if (visited[u] == false) {
                q.push(u);
                visited[u] = true;
            }
        }
    }
}
