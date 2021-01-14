#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result = (result + k) % i;
    }
    cout << result + 1;
    return 0;
}