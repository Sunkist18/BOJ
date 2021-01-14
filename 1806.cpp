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
vector<int> field;
int n, s, var;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s >> var;
    field.emplace_back(var);
    for (int i = 1; i < n; i++) {
        cin >> var;
        field.emplace_back(var + field[i - 1]);
    }
    int start = 0, end = 0;
    int result = (*(field.end() - 1) >= s ? *(field.end() - 1) : LONG_LONG_MAX);
    while (true) {
        if (field[end] - field[start] >= s) {
            result = min(result, end - start++);
        } else if (end == n) {
            break;
        } else {
            end++;
        }
    }
    cout << (result == LONG_LONG_MAX ? 0 : result);
    return 0;
}