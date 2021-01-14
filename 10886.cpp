#include <bits/stdc++.h>

using namespace std;
string cmd;
int t, args;
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> cmd;
        if (cmd == "push_front") {
            cin >> args;
            dq.push_front(args);
        } else if (cmd == "push_back") {
            cin >> args;
            dq.push_back(args);
        } else if (cmd == "pop_front") {
            if (!dq.empty()) {
                cout << dq.front() << '\n';
                dq.pop_front();
            } else {
                cout << -1 << '\n';
            }
        } else if (cmd == "pop_back") {
            if (!dq.empty()) {
                cout << dq.back() << '\n';
                dq.pop_back();
            } else {
                cout << -1 << '\n';
            }
        } else if (cmd == "size") {
            cout << dq.size() << '\n';
        } else if (cmd == "empty") {
            cout << dq.empty() << '\n';
        } else if (cmd == "front") {
            if (!dq.empty()) {
                cout << dq.front() << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else if (cmd == "back") {
            if (!dq.empty()) {
                cout << dq.back() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}