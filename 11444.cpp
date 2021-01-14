#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int, int> pii;
unordered_map<string, int> field;
string input;

int dp(string line) {
    if (field[line] != 0 or line == "0")
        return field[line];
    field[line] = 
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> input;
    field["0"] = 0;
    field["1"] = 1;
    field["2"] = 1;
    cout << dp(input);
    return 0;
}