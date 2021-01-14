#include <bits/stdc++.h>
using namespace std;
unsigned int a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a;
    while (a) {
        cout << a << ' ' << (a & 1) << '\n';
        a >>= 1;
    }
    return 0;
}