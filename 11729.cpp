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
int cnt = 0;
string result;

void hanoi(int num, int from, int via, int to) {
    cnt++ ;
    if (num == 1) {
        result += to_string(from) + ' ' + to_string(to) + '\n';
        return;
    }
    hanoi(num - 1, from, to, via);
    result += to_string(from) + ' ' + to_string(to) + '\n';
    hanoi(num - 1, via, from, to);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    hanoi(n, 1, 2, 3);
    cout << cnt << '\n' << result;
    return 0;
}