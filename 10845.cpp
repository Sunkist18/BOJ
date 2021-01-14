#include <bits/stdc++.h>

using namespace std;
string cmd;
int t, args;
queue<int> que;

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
            que.push(args);
        } else if (cmd == "pop") {
            if (!que.empty()) {
                cout << que.front() << '\n';
                que.pop();
            } else {
                cout << -1 << '\n';
            }
        } else if (cmd == "size") {
            cout << que.size() << '\n';
        } else if (cmd == "empty") {
            cout << que.empty() << '\n';
        } else if (cmd == "front") {
            if (!que.empty()) {
                cout << que.front() << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else if (cmd == "back") {
            if (!que.empty()) {
                cout << que.back() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}