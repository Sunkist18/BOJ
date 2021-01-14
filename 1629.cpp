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
int a, b, c;

int powering(int n, int k) {
    if (k == 0)
        return 1;
    if (k == 1)
        return n;
    if (k % 2 == 0) {
        int half = powering(n, k / 2) % c;
        return (half * half) % c;
    }
    else {
        int half = powering(n, k / 2) % c;
        return (powering(half, 2) * n) % c;
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> c;
    cout << powering(a, b) % c;
    return 0;
}