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

int n;
bool field[1024][2048];

void draw(int x, int y, int scale) {
    if (x < 0 or y < 0) {
        return;
    }
    if (scale == 0) {
        /*
         *   *
         *  * *
         * *****
         */
        field[y][x + 0] = true;
        field[y][x + 1] = true;
        field[y][x + 2] = true;
        field[y][x + 3] = true;
        field[y][x + 4] = true;
        field[y - 1][x + 1] = true;
        field[y - 1][x + 3] = true;
        field[y - 2][x + 2] = true;
        return;
    }
    draw(x, y, scale - 1);
    draw(x + 3 * (int)pow(2, scale), y, scale - 1);
    draw(x + (scale * 3), y - (scale * 3), scale - 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int m = n;
    int i = n / 3;
    int var = 1;
    int cnt = 0;
    while (var != i) {
        var *= 2;
        cnt += 1;
    }
    n = cnt;
    draw(0, 3 * (int)pow(2, n - 1) - 1, n - 1);
    for (int i = 0; i < 3 * (int)pow(2, n - 1); i++) {
        for (int j = 0; j < n * 6 * (int)pow(2, n - 1); j++) {
            cout << ((field[i][j]) ? '*' : ' ');
        }
        cout << '\n';
    }
    return 0;
}