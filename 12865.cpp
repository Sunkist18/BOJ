#include <bits/stdc++.h>

#define int long long
using namespace std;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)

int sum() { return 0; }

template<typename T, typename... Args>
auto sum(T a, Args... args) { return a + sum(args...); }

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}

template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

typedef pair<int, int> pii;
int n, k;
int w[100 + 1], v[100 + 1];
int dp[100 + 1][100000 + 1];

int knapsack(int i, int weight) {
    if (i == 0 or weight == 0)
        return 0;
    if (dp[i][weight] != 0)
        return dp[i][weight];
    int unselected_value = knapsack(i - 1, weight);
    if (w[i] > weight) {
        return dp[i][weight] = unselected_value;
    }
    return dp[i][weight] = max(v[i] + knapsack(i - 1, weight - w[i]), unselected_value);
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    cout << knapsack(n, k);
    return 0;
}