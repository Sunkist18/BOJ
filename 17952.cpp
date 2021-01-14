#include <bits/stdc++.h>

#define int long long
using namespace std;

// global variables here
typedef pair<int, int> pos;
#define score first
#define time second
stack<pos> field;
int n, cmd, a, t;
int result;

#undef int

int main() {
#define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        // new task here
        if (cmd == 1) {
            cin >> a >> t;
            field.push({a, t});
        }
        if (!field.empty()) {
            field.top().time -= 1;
            if (field.top().time <= 0) {
                result += field.top().score;
                field.pop();
            }
        }
    }
    cout << result << '\n';
    return 0;
}