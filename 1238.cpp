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
vector<vector<pii>> field(1000 + 1);
int n, m, x;
int from, to, t;

vector<int> dijkstra(int start) {
    vector<int> dist(1000 + 1, LONG_LONG_MAX);
    dist[start] = 0;
    priority_queue<pii> pq;
    pq.push({0, start});
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

    cin >> n >> m >> x;;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> t;
        field[from].emplace_back(to, t);
    }
    int result = 0;
    vector<int> back = dijkstra(x);
    for (int v = 1; v <= n; v++) {
        if (v == x) continue;
        int var = dijkstra(v)[x] + back[v];
        result = max(result, var);
    }
    cout << result;
    return 0;
}