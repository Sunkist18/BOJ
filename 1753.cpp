#include <bits/stdc++.h>

#define int long long
using namespace std;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)

int sum() { return 0; }

template<typename T, typename... Args>
auto sum(T a, Args... args) { return a + sum(args...); }

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}

template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

typedef pair<int, int> pii;
int V, E, start_node;
vector<vector<pii>> field;

vector<int> dijkstra(int v) {
    vector<int> dist(V + 1, LONG_LONG_MAX);
    dist[v] = 0;
    priority_queue<pii> pq;
    pq.push({0, v});

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;
        for (auto there : field[here]) {
            int next_node = there.first;
            int next_cost = cost + there.second;

            if (dist[next_node] > next_cost) {
                dist[next_node] = next_cost;
                pq.push({-next_cost, next_node});
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
    cin >> V >> E;
    field = vector<vector<pii>>(V + 1);
    cin >> start_node;
    for (int i = 0; i < E; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        field[from].emplace_back(to, cost);
    }
    vector<int> result = dijkstra(start_node);
    for (int i = 1; i < result.size(); i++)
        cout << (result[i] == LONG_LONG_MAX ? "INF" : to_string(result[i])) << '\n';
    return 0;
}