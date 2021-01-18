// https://www.acmicpc.net/problem/18883.cpp

#include <bits/stdc++.h>

#define int long long

using namespace std;
typedef pair<int, int> pii;
int x, y;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> y >> x;
    for (int i = 0; i < y; i++) for (int j = 0; j < x; j++) cout << (x * i + (j + 1)) << " \n"[j == x - 1];
    return 0;
}