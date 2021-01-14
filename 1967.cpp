#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int, int> pii;
int n, i, here, there, cost;
vector<vector<pii>> nodes;
bool visited[10001];

vector<int> bfs(int v) {
    memset(visited, false, sizeof(visited));
    vector<int> dist(n + 1);
    for (i = 0; i <= n; i++)
        dist[i] = 0;

    queue<pii> que;
    visited[v] = true;
    que.push({v, 0});
    while (!que.empty()) {
        tie(here, cost) = que.front();
        que.pop();
        for (auto p : nodes[here]) {
            if (!visited[p.first]) {
                visited[p.first] = true;
                que.push({p.first, p.second + cost});
                dist[p.first] = p.second + cost;
            }
        }
    }
    return dist;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    nodes.resize(n + 1);
    for (i = 0; i < n; i++) {
        cin >> here >> there >> cost;
        nodes[here].emplace_back(there, cost);
        nodes[there].emplace_back(here, cost);
    }
    vector<int> var_vector(bfs(1));
    int max_node = 1;
    int max_value = 0;
    for (i = 1; i <= n; i++) {
        if (var_vector[i] > max_value) {
            max_node = i;
            max_value = var_vector[i];
        }
    }
    vector<int> las_vector(bfs(max_node));
    int result = 0;
    for (i = 1; i <= n; i++)
        result = max(result, las_vector[i]);
    cout << result;
    return 0;
}