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

int field[8];
double lo, hi, mid;

pair<double, double> where(double Ax, double Ay, double Bx, double By, double percent) {
    return {Ax + (Bx - Ax) * percent / 1000000.0, Ay + (By - Ay) * percent / 1000000.0};
}

double dist(double percent) {
    pair<double, double> pos1 = where(field[0], field[1], field[2], field[3], percent);
    pair<double, double> pos2 = where(field[4], field[5], field[6], field[7], percent);
    return (pos1.first - pos2.first) * (pos1.first - pos2.first) +
           (pos1.second - pos2.second) * (pos1.second - pos2.second);
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int &i : field)
        cin >> i;
    lo = 0.0;
    hi = 1000000.0;
    while (fabs(hi - lo) > 2e-6) {
        if (dist(lo) <= dist(hi))
            hi = (lo + hi) / 2;
        else
            lo = (lo + hi) / 2;
    }
    cout << sqrt(dist(lo));
    return 0;
}