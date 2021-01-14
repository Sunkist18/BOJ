#include <bits/stdc++.h>

using namespace std;
int n, args;
set<int> field;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> args;
        field.insert(args);
    }
    cin >> n;
    while (n--) {
        cin >> args;
        cout << field.count(args) << ' ';
    }
    return 0;
}