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
int a, b;

int bfs(int start) {
    queue<pii> que;
    que.push({start, 1});
    while (!que.empty()) {
        pii q = que.front(); que.pop();
        if (q.first == b)
            return q.second;
        if (q.first * 2 <= b)
            que.push({q.first * 2, q.second + 1});
        if (q.first * 10 + 1 <= b)
            que.push({q.first * 10 + 1, q.second + 1});
    }
    return -1;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    cout << bfs(a);
    return 0;
}