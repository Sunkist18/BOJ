#include <bits/stdc++.h>

#define int long long
using namespace std;

// global variables here
typedef pair<int, int> pos;
#define x first
#define y second

map<int, vector<int>> field;
int dp[1000 + 1];
int n, m;
int var1, var2;

int getDP(int node) {
    if (dp[node] != 0) {
        return dp[node];
    }
    int addition = 0;
    for (auto e : field[node]) {
        addition = max(addition, getDP(e));
    }
    return dp[node] = 1 + addition;
}

#undef int

int main() {
#define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> var1 >> var2;
        field[var2].push_back(var1);
    }
    for (int i = 1; i <= n; i++) {
        cout << getDP(i) << ' ';
    }
    return 0;
}