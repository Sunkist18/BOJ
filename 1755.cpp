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


string rep[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<pair<string, int>> field;
int n, m;

string replace(int number) {
    string result;
    while (number > 0) {
        result = rep[number % 10] + ' ' + result;
        number /= 10;
    }
    return result;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = n; i <= m; i++)
        field.emplace_back(replace(i), i);
    sort(field.begin(), field.end());
    int count = 1;
    for (auto i : field) {
        cout << i.second << " \n"[count % 10 == 0 && count != 0];
        count ++;
    }
    return 0;
}