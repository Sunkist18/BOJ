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

typedef pair<int, int> pos;

int n, result[2], x, y;
char var;
bool visited[2][100][100];
char field[2][100][100];
vector<pos> delta = {{0,  1},
                     {1,  0},
                     {-1, 0},
                     {0,  -1}};

void bfs(pos start, int space) {
    result[space]++;
    char flag = field[space][start.second][start.first];
    visited[space][start.second][start.first] = true;
    queue<pos> que;
    que.push(start);
    while (!que.empty()) {
        pos q = que.front();
        que.pop();
        for (auto p_pos : delta) {
            tie(x, y) = p_pos;
            if (0 <= q.first + x and q.first + x < n and 0 <= q.second + y and q.second + y < n) {
                if (!visited[space][q.second + y][q.first + x] and field[space][q.second + y][q.first + x] == flag) {
                    visited[space][q.second + y][q.first + x] = true;
                    que.push({q.first + x, q.second + y});
                }
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> var;
            field[0][i][j] = var;
            field[1][i][j] = (var == 'G' ? 'R' : var);
        }
    }
    for (int space = 0; space < 2; space++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!visited[space][j][i])
                    bfs({i, j}, space);
    cout << result[0] << ' ' << result[1];
    return 0;
}