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
bool var, field[100][100];
map<int, vector<int>> board;

void bfs(int i);

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> var;
            if (var)
                board[i].push_back(j);
        }
    for (int i = 0; i < n; i++)
        bfs(i);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << field[i][j] << " \n"[j == n - 1];
    return 0;
}

void bfs(int i) {
    bool visited[100];
    memset(visited, false, sizeof(visited));
    queue<int> que;
    que.push(i);
    while (!que.empty()) {
        int q = que.front();
        que.pop();
        for (auto k : board[q]) {
            if (!visited[k]) {
                visited[k] = true;
                field[i][k] = true;
                que.push(k);
            }
        }
    }
}
