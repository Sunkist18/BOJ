#include <bits/stdc++.h>

#define int long long
using namespace std;

// global variables here
typedef pair<int, vector<int>> building;
#define time first
#define pre second

map<int, building> field;

int n, var;
int dp[500 + 1];

int getDP(int node) {
    if (dp[node] != 0) {
        return dp[node];
    }
    int addition = 0;
    for (auto e : field[node].pre) {
        addition = max(getDP(e), addition);
    }
    return dp[node] = field[node].time + addition;;
}

#undef int
int main() {
#define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> field[i].time;
        while (true) {
            cin >> var;
            if (var == -1) {
                break;
            }
            field[i].pre.push_back(var);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << getDP(i) << '\n';
    }
    return 0;
}