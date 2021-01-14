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

#define x first
#define y second
typedef pair<int, int> pii;

int n, m, var, result = LONG_LONG_MAX;
vector<pii> var_vector;
vector<pii> houses;
vector<pii> chickens;

int distance(pii a, pii b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void calc() {
    int sum = 0;
    for (auto house : houses) {
        int d = LONG_LONG_MAX;
        for (auto chicken : var_vector)
            d = min(d, distance(chicken, house));
        sum += d;
    }
    result = min(result, sum);
}

void dfs(int index, int cnt) {
    if (cnt == 0)
        return calc();
    for (int i = index; i < chickens.size(); i++) {
        var_vector.push_back(chickens[i]);
        dfs(i + 1, cnt - 1);
        var_vector.pop_back();
    }
}

void Input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> var;
            if (var == 1)
                houses.emplace_back(j, i);
            if (var == 2)
                chickens.emplace_back(j, i);
        }
    }
}

void Solve() {
    dfs(0, m);
    cout << result << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Solve();
    return 0;
}
