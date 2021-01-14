#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int field[100][100], n, color = 0;
pii delta[4] = {
        {0,  1},
        {1,  0},
        {0,  -1},
        {-1, 0}
};
bool visited[100][100];

void coloring(int x, int y) {
    color++;
    queue<pii> que;
    que.push({x, y});
    field[y][x] = color;
    while (!que.empty()) {
        tie(x, y) = que.front();
        que.pop();
        for (auto there : delta) {

        }
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
            cin >> field[y][x];

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (!visited[y][x]) {
                visited[y][x] = true;
                coloring(x, y);
            }
        }
    }


    return 0;
}