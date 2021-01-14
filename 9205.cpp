#include <bits/stdc++.h>

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

typedef pair<int, int> pos;

int t, n, x, y;

bool isCondition(pos a, pos b) {
    return abs(a.first - b.first) + abs(a.second - b.second) <= 1000;
}

void Solve() {
    cin >> n;

    map<int, vector<int>> field;
    pos building[n + 2];
    bool visited[n + 2];
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n + 2; i++) {
        cin >> x >> y;
        building[i] = {x, y};
        for (int j = 0; j < i; j++) {
            if (isCondition(building[i], building[j])) {
                field[i].push_back(j);
                field[j].push_back(i);
            }
        }
    }
    queue<int> que;
    que.push(0);
    visited[0] = true;
    while (!que.empty()) {
        int q = que.front();
        que.pop();
        for (auto p : field[q]) {
            if (p == n + 1) {
                cout << "happy\n";
                return;
            }
            if (!visited[p]) {
                visited[p] = true;
                que.push(p);
            }
        }
    }
    cout << "sad\n";
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
        Solve();
    return 0;
}