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

//class integer {
//    string value;
//
//    string operator+(const integer &str) {
//        string a, b;  // operate a + b ( a > b )
//        if (this->value.length() > str.value.length()) {
//            a = this->value;
//            b = str.value;
//        } else {
//            b = this->value;
//            a = str.value;
//        }
//        for (int i = 0; i < b.length())
//    }
//};

int C[100 + 1][100 + 1];

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i <= 100; i++)
        C[i][0] = 1;
    for (int n = 1; n <= 100; n++)
        for (int r = 1; r <= n; r++)
            C[n][r] = C[n - 1][r] + C[n - 1][r - 1];
    int n, m;
    cin >> n >> m;
    cout << C[n][m];
    return 0;
}