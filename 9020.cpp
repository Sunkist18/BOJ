#include <bits/stdc++.h>

#define int long long
using namespace std;

// global variables here
bool field[5000 + 1];
int n, num;

#undef int

int main() {
#define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Initialization
    for (int i = 1; i <= 10000; i++)
        field[i] = true;
    field[1] = false;
    for (int i = 2; i <= 10000; i++) {
        if (field[i]) {
            for (int j = i + i; j <= 10000; j += i) {
                field[j] = false;
            }
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        for (int cur = num / 2; cur >= 1; cur--) {
            if (field[cur] && field[num - cur]) {
                cout << cur << ' ' << num - cur << '\n';
                break;
            }
        }
    }
    return 0;
}