#include <bits/stdc++.h>

using namespace std;
string cmd;
int t, args;
stack<int> stk;

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> args;
            stk.push(args);
        } else if (cmd == "pop") {
            if (!stk.empty()) {
                cout << stk.top() << '\n';
                stk.pop();
            } else {
                cout << -1 << '\n';
            }
        } else if (cmd == "size") {
            cout << stk.size() << '\n';
        } else if (cmd == "empty") {
            cout << stk.empty() << '\n';
        } else if (cmd == "top") {
            if (!stk.empty()) {
                cout << stk.top() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}