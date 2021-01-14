#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int, int> pii;
int n, k, m, a, b;

// 0 for None, 1 for death, 2 for life
bool visited[201];
int dp[201][201];
unordered_map<int, pii> field;


int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        field[i] = {a, b};
    }
    for (m--)
    return 0;
}