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
int max_x, max_y;
int field[101][101];

int square_value(int x1, int y1, int x2, int y2) {
    if (x1 > x2 or y1 > y2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    return field[y2][x2] - field[y2][x1 - 1] - field[y1 - 1][x2] + field[y1 - 1][x1 - 1];
}

void Solve() {
    int result = 0;
    string var;
    cin >> max_y >> max_x;
    for (int y = 1; y <= max_y; y++) {
        cin >> var;
        for (int x = 1; x <= max_x; x++) {
            field[y][x] = var[x - 1] - '0';
            field[y][x] += field[y][x - 1] + field[y - 1][x] - field[y - 1][x - 1];
        }
    }

    /*   case1   case2   case3   case4   case5   case6
     *  ┏━┳━┳━┓ ┏━┳━━━┓ ┏━━━┳━┓ ┏━━━━━┓ ┏━━┳━━┓ ┏━━━━━┓
     *  ┃ ┃ ┃ ┃ ┃ ┣━━━┫ ┣━━━┫ ┃ ┣━━━━━┫ ┃  ┃  ┃ ┣━━┳━━┫
     *  ┗━┻━┻━┛ ┗━┻━━━┛ ┗━━━┻━┛ ┣━━━━━┫ ┣━━┻━━┫ ┃  ┃  ┃
     *                          ┗━━━━━┛ ┗━━━━━┛ ┗━━┻━━┛
     */

    // case 1, 2, 3, 5, 6, 4

    for (int x1 = 2; x1 <= max_x -1; x1++)
        for (int x2 = x1 + 1; x2 <= max_x; x2++)
            result = max(result, square_value(1, 1, x1 - 1, max_y)
                                 * square_value(x1, 1, x2 - 1, max_y)
                                 * square_value(x2, 1, max_x, max_y));
    for (int x1 = 2; x1 <= max_x; x1++)
        for (int y1 = 2; y1 <= max_y; y1++) {
            result = max(result, square_value(1, 1, x1 - 1, max_y)
                                 * square_value(x1, 1, max_x, y1 - 1)
                                 * square_value(x1, y1, max_x, max_y));
            result = max(result, square_value(1, 1, x1 - 1, y1 - 1)
                                 * square_value(1, y1, x1 - 1, max_y)
                                 * square_value(x1, 1, max_x, max_y));
            result = max(result, square_value(1, 1, x1 - 1, y1 - 1)
                                 * square_value(x1, 1, max_x, y1 - 1)
                                 * square_value(1, y1, max_x, max_y));
            result = max(result, square_value(1, 1, max_x, y1 - 1)
                                 * square_value(1, y1, x1 - 1, max_y)
                                 * square_value(x1, y1, max_x, max_y));
        }
    for (int y1 = 2; y1 <= max_y - 1; y1++)
        for (int y2 = y1 + 1; y2 <= max_y; y2++)
            result = max(result, square_value(1, 1, max_x, y1 - 1)
                                 * square_value(1, y1, max_x, y2 - 1)
                                 * square_value(1, y2, max_x, max_y));

    cout << result << '\n';
}

int32_t main() {
    int t = 1;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    t = 3;
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (t--)
        Solve();
    return 0;
}