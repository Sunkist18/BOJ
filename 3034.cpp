#include <bits/stdc++.h>

#define int long long
using namespace std;

// global variables here
int n, w, h, var;
#undef int

int main() {
#define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w >> h;
    for (int i = 0; i < n; i++) {
        cin >> var;
        cout << (var * var <= w * w + h * h ? "DA" : "NE") << '\n';
    }
    return 0;
}