#include <bits/stdc++.h>

using namespace std;
int n, k;
deque<int> field;

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        field.push_back(i);

    cout << "<";
    while (field.size() != 1) {
        for (int i = 0; i < k - 1; i++) {
            field.push_back(field.front());
            field.pop_front();
        }
        cout << field.front() << ", ";
        field.pop_front();
    }
    cout << field.front() << ">";
    return 0;
}