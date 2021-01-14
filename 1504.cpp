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
int n, e;
int from, to, t;
vector<vector<pii>> field(800 + 1);

vector<int> dijkstra(int v) {
    vector<int> dist(n + 1, LONG_LONG_MAX);
    dist[v] = 0;
    priority_queue<pii> pq;
    pq.push({0, v});
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        for (auto next : field[here]) {
            int there = next.first;
            int nextDist = cost + next.second;

            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push({-nextDist, there});
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

    cin >> n >> e;
    while (e--) {
        cin >> from >> to >> t;
        field[from].emplace_back(to, t);
        field[to].emplace_back(from, t);
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> v = {v1, v2};
    int result = LONG_LONG_MAX;
    vector<int> start_node = dijkstra(1);
    for (int i = 0; i <= 1; i++) {
        int root1 = start_node[v[i]];
        int root2 = dijkstra(v[i])[v[1 - i]];
        int root3 = dijkstra(v[1 - i])[n];
        if (root1 != LONG_LONG_MAX and root2 != LONG_LONG_MAX and root3 != LONG_LONG_MAX)
            result = min(result, root1 + root2 + root3);
    }
    cout << (result == LONG_LONG_MAX ? -1 : result);
    return 0;
}