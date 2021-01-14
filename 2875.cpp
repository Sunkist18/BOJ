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

int n, m, k;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    int team = 0;
    while (n >= 2 and m >= 1) {
        n -= 2;
        m -= 1;
        team += 1;
    }
    cout << team - (n + m - k < 0 ? (long long)ceil(double(k - n - m) / 3.0) : 0);
    return 0;
}