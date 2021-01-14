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

bool visited[10000];
int parent[10000];
char action[10000];
int a, b, t, var;

void Solve() {
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    memset(action, 0, sizeof(action));
    cin >> a >> b;

    queue<int> q;
    q.push(a);
    visited[a] = true;
    bool flag = false;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (auto k : "DSLR") {
            var = (k == 'D') ? var = (p * 2 > 9999 ? p * 2 % 10000 : p * 2) :
                  (k == 'S' ? (p == 0 ? 9999 : p - 1) :
                   (k == 'L' ? ((p * 10) % 10000) + (p / 1000) :
                    ((p % 10) * 1000) + (p / 10)));
            if (!visited[var]) {
                visited[var] = true;
                action[var] = k;
                parent[var] = p;
                q.push(var);
            }
        }
    }
    string result;
    while (a != b) {
        result += action[b];
        b = parent[b];
    }
    reverse(result.begin(), result.end());
    cout << result << '\n';
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
        Solve();
    return 0;
}