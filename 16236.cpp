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

class cmp {
public:
    bool operator()(pii a, pii b) {
        if (a.y < b.y)
            return true;
        if (a.y > b.y)
            return false;
        return (a.x < b.x);
    }
};

vector<pii> delta = {{1,  0},
                     {0,  1},
                     {-1, 0},
                     {0,  -1}};

int n, dx, dy, qx, qy, size = 2, result = 0;
int field[20][20];
int visited[20][20];

pair<pii, int> find_location(pii pos) {
    set<pii, cmp> ret;
    int init_x, init_y;

    tie(init_x, init_y) = pos;
    for (int i = 0; i < n; i++)
        memset(visited[i], 0, sizeof(visited[i]));
    visited[init_y][init_x] = 1;
    int dist = LONG_LONG_MAX;
    queue<pii> que;
    que.push(pos);
    while (!que.empty()) {
        pii q = que.front();
        que.pop();
        tie(qx, qy) = q;
        for (auto p : delta) {
            tie(dx, dy) = p;
            if (0 <= qx + dx and qx + dx < n and 0 <= qy + dy and qy + dy < n) {
                if (!visited[qy + dy][qx + dx] and visited[qy][qx] <= dist) {
                    if (field[qy + dy][qx + dx] == size or field[qy + dy][qx + dx] == 0) {
                        visited[qy + dy][qx + dx] = visited[qy][qx] + 1;
                        que.push({qx + dx, qy + dy});
                    } else if (field[qy + dy][qx + dx] < size) {
                        visited[qy + dy][qx + dx] = visited[qy][qx] + 1;
                        dist = visited[qy][qx];
                        ret.insert({qx + dx, qy + dy});
                    }
                }
            }
        }
    }
    if (ret.empty())
        return {{-1, -1}, 0};
    return {*ret.begin(), visited[ret.begin()->y][ret.begin()->x] - 1};
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Initialization
    pii crt_loc, next_loc;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> field[i][j];
            if (field[i][j] == 9) {
                field[i][j] = 0;
                crt_loc = {j, i};
            }
        }
    }

    int eat_count = 0;
    if (find_location(crt_loc).x.x == -1) {
        cout << result;
        return 0;
    }
    do {
        int addition;
        tie(next_loc, addition) = find_location(crt_loc);
        tie(qx, qy) = next_loc;
        field[qy][qx] = 0;
        eat_count++;
        if (size == eat_count) {
            size++;
            eat_count = 0;
        }
        result += addition;
        crt_loc = next_loc;
    } while (find_location(crt_loc).x.x != -1);
    cout << result;
    return 0;
}