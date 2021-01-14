// https://www.acmicpc.net/problem/9466

#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> field;
vector<int> color;

void clearing(int begin, int end) {
    if (begin == end) return;
    color[begin] = -2;
    clearing(field[begin], end);
}

void coloring(int start, int now, int flag) {
    if (color[now] == -1) {
        color[now] = flag;
        coloring(start, field[now], flag);
    } else
        clearing(start, now);
}

void solve() {
    cin >> n;
    field.resize(n);
    color.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> field[i];
        field[i] -= 1;
        color[i] = -1;
    }
    for (int i = 0; i < n; i++)
        if (color[i] == -1)
            coloring(i, i, i);
    int result = 0;
    for (int i = 0; i < n; i++)
        result += color[i] < 0;

    cout << result << '\n';
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
        solve();
    return 0;
}