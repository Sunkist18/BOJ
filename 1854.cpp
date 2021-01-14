#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int, int> pii;
int n, m, k;
map<int, vector<pii>> field;
vector<priority_queue<int>> result;

void dijkstra(int v) {
    vector<int> dist(n + 1, LONG_LONG_MAX);
    dist[v] = 0;
    priority_queue<pii> pq;
    pq.push({0, v});
    result[v].push(0);

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;
        for (auto there : field[here]) {
            int next_node = there.first;
            int next_cost = cost + there.second;

            if(result[next_node].size() < k) {
                result[next_node].push(-next_cost);
            } else {
                result[next_node].pop();
                result[next_node].push(-next_cost);
            }

            if (dist[next_node] > next_cost) {
                dist[next_node] = next_cost;
                pq.push({-next_cost, next_node});
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    result.resize(n + 1);
    while (m--) {
        int f, t, c;
        cin >> f >> t >> c;
        field[f].emplace_back(t, c);
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        if (result[i].size() < k) {
            cout << -1 << '\n';
            continue;
        }
        result[i].pop();
        cout << -result[i].top() << '\n';
    }
    return 0;
}