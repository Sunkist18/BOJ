// https://www.acmicpc.net/problem/1260

#include <bits/stdc++.h>

#define int long long
using namespace std;
map<int, vector<int>> field;
map<int, bool> visited;
int from, to;
int n, m, v;

void bfs() {
    int start = v;
    visited[start] = true;
    queue<int> que;
    que.push(start);
    while (!que.empty()) {
        int here = que.back();
//        cout << here << ' ';
        que.pop();
        sort(field[here].begin(), field[here].end());
        for (auto w: field[here]) {
            if (!visited[w]) {
                cout << w << visited[w] << '\n';
                visited[w] = true;
                que.push(w);
            }
        }
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> v;
    while (m--) {
        cin >> from >> to;
        field[from].emplace_back(to);
        field[to].emplace_back(from);
    }
    bfs();
    return 0;
}