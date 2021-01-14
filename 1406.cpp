#include <bits/stdc++.h>

using namespace std;
deque<char> l_dq;
deque<char> r_dq;
string init;
int n;
char cmd, args;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> init;
    for (auto chr : init)
        l_dq.push_back(chr);
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == 'L') {
            if (!l_dq.empty()) {
                r_dq.push_front(l_dq.back());
                l_dq.pop_back();
            }
        } else if (cmd == 'D') {
            if (!r_dq.empty()) {
                l_dq.push_back(r_dq.front());
                r_dq.pop_front();
            }
        } else if (cmd == 'B') {
            if (!l_dq.empty()) {
                l_dq.pop_back();
            }
        } else {
            cin >> args;
            l_dq.push_back(args);
        }
    }
    for (auto chr : l_dq)
        cout << chr;
    for (auto chr : r_dq)
        cout << chr;
    return 0;
}