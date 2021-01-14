#include <bits/stdc++.h>

using namespace std;
int n, args;
priority_queue<int> field;

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> args;
        if (args != 0) {
            field.push(-args);
            continue;
        } else if (field.empty()) {
            cout << 0 << '\n';
        } else {
            cout << -field.top() << '\n';
            field.pop();
        }
    }
    return 0;
}