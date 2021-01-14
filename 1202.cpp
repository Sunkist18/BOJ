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
int n, k;
int m, v, c;
priority_queue<int> pq;
vector<pii> gem;
vector<int> bag;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    while (n--) {
        cin >> m >> v;
        gem.emplace_back(m, v);
    }
    while (k--) {
        cin >> c;
        bag.emplace_back(c);
    }
    sort(gem.begin(), gem.end());
    sort(bag.begin(), bag.end());

    int index = 0, result = 0;
    for (auto cap : bag) {
        while (index < gem.size() and gem[index].first <= cap)
            pq.push(gem[index++].second);

        if (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    }
    cout << result << '\n';
    return 0;
}