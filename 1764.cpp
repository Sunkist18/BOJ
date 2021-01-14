#include <bits/stdc++.h>

using namespace std;
int n, m;
string args;
map<string, bool> field;
set<string> result;

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (n--) {
        cin >> args;
        field[args] = true;
    }
    while (m--) {
        cin >> args;
        if (field[args])
            result.insert(args);
    }
    cout << result.size() << '\n';
    for (auto element : result)
        cout << element << '\n';
    return 0;
}