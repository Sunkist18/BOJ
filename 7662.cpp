#include <bits/stdc++.h>

using namespace std;

int t, n, var;
char cmd;

void Solve() {
    multiset<int> field;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd >> var;
        if (cmd == 'I')
            field.insert(var);
        else if (!field.empty())
            field.erase((var == 1 ? --field.end() : field.begin()));
    }
    if (!field.empty())
        cout << *(--field.end()) << ' ' << *field.begin() << '\n';
    else
        cout << "EMPTY\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
        Solve();
    return 0;
}