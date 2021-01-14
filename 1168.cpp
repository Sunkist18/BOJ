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

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> field;
    priority_queue<int> a;
    a.

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        field.push(i);
    cout << '<';
    while (!field.empty()) {
        for (int i = 1; i < k; i++) {
            field.push(field.front());
            field.pop();
        }
        cout << field.front() << (field.size() == 1 ? "" : ", ");
        field.pop();
    }
    cout << '>';
    return 0;
}