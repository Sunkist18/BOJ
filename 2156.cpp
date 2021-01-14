#include <bits/stdc++.h>
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

int glass[10000 + 1], n;
int dp[10000 + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> glass[i];
    }
    if (n < 3) {
        cout << accumulate(glass, glass + n, 0);
        return 0;
    }
    dp[0] = glass[0];
    dp[1] = glass[0] + glass[1];
    dp[2] = max(dp[1], max(glass[0] + glass[2], glass[1] + glass[2]));
    for (int i = 3; i < n; i++) {
        // Not drinking here...
        int case_1 = dp[i - 1];
        // Drinking with 1 time...
        int case_2 = dp[i - 2] + glass[i];
        // Drinking with 2 times...
        int case_3 = dp[i - 3] + glass[i - 1] + glass[i];
        dp[i] = max(case_1, max(case_2, case_3));
    }
    cout << dp[n - 1];
    return 0;
}