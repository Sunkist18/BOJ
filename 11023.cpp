// https://www.acmicpc.net/problem/11023.cpp

#include <bits/stdc++.h>

#define int long long

using namespace std;
typedef pair<int, int> pii;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int var, sum = 0;
    while (cin >> var) sum += var;
    cout << sum;
    return 0;
}