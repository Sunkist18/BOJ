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
int n, m;
vector<int> stk;
bool visited[10];

void Combination(int i, int depth) {
    if (depth == 0) {
        for (auto k : stk) {
            cout << k << ' ';
        }
        cout << '\n';
        return;
    }
    for (int k = 1; k <= n; k++) {
        if (!visited[k]) {
            stk.push_back(k);
            visited[k] = false;
            Combination(k, depth - 1);
            stk.pop_back();
            visited[k] = false;
        }
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    Combination(0, m);
    return 0;
}