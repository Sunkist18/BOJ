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
int N, M;
int n, var;
vector<int> illuminati;
int isIlluminati[51];
map<int, set<int>> field;
vector<vector<int>> partys;

void bfs(int moder);

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    cin >> n;
    for (int i = 0; i < n; i++) {
        // Note People who knows truth.
        cin >> var;
        isIlluminati[var] = true;
        illuminati.emplace_back(var);
    }
    for (int party_index = 0; party_index < M; party_index++) {
        cin >> n;
        partys.emplace_back();
        for (int i = 0; i < n; i++) {
            cin >> var;
            // Note Party participants.
            partys[party_index].emplace_back(var);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                // Make Node with Party participants.
                field[partys[party_index][i]].insert(partys[party_index][j]);
                field[partys[party_index][j]].insert(partys[party_index][i]);
            }
        }
    }
    for (auto admin : illuminati) {
        for (auto moder : field[admin]) {
            isIlluminati[moder] = true;
            bfs(moder);
        }
    }

    int result = 0;
    for (int i = 0; i < M; i++) {
        bool flag = true;
        for (auto person : partys[i]) {
            if (isIlluminati[person]) {
                flag = false;
                break;
            }
        }
        result += flag;
    }
    cout << result;
    return 0;
}

void bfs(int moder) {
    queue<int> que;
    que.push(moder);
    while (!que.empty()) {
        int q = que.front(); que.pop();
        for (auto p : field[q]) {
            if (!isIlluminati[p]) {
                isIlluminati[p] = true;
                que.push(p);
            }
        }
    }
}
