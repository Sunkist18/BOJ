#include <bits/stdc++.h>

#define int long long
using namespace std;
int dp[51], n;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1 + 1 + 1;
    cin >> n;
    for (int i = 3; i <= n; i++)
        dp[i] = 1 + dp[i - 1] + dp[i - 2];
    cout << dp[n] % 1000000007;
    return 0;
}