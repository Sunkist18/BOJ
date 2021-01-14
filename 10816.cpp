#include <bits/stdc++.h>

using namespace std;
unordered_map<int, int> field;
int n, args;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> args;
        field[args]++;
    }
    cin >> n;
    while (n--) {
        cin >> args;
        cout << field[args] << ' ';
    }
    return 0;
}