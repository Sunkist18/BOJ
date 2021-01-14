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

struct cmp {
    bool operator()(int i, int j) {
        if (abs(i) < abs(j))
            return true;
        else if (abs(i) > abs(j))
            return false;
        return i < j;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, var;
    cin >> n;
    multiset<int, cmp> field;
    for (int i = 0; i < n; i++) {
        cin >> var;
        if (var == 0) {
            if (field.empty())
                cout << "0\n";
            else {
                cout << *field.begin() << '\n';
                field.erase(field.begin());
            }
        }
        else
            field.insert(var);
    }
    return 0;
}