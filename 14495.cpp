#include <bits/stdc++.h>

#define int long long
using namespace std;
int dp[116], n;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    dp[0] = dp[1] = dp[2] = 1;
    for (int i = 3; i < n; i++)
        dp[i] = dp[i - 1] + dp[i - 3];
    cout << dp[n - 1];
    return 0;
}