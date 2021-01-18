// https://www.acmicpc.net/problem/2003.cpp

#include <bits/stdc++.h>

#define int long long

/**************************************
 * 결과   : 
 * 시간   : 
 * 공간   :
 * ************************************
 * 정답 풀이
 * ------------------------------------
 * 
 * 
 * 오답 노트
 * ------------------------------------
 * 
 * ************************************/

using namespace std;
typedef pair<int, int> pii;

int n, m, low = 0, high = 0, sum = 0, result = 0;
vector<int> field;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    field.resize(n);
    for (auto &k : field) cin >> k;
    while (42) {
        if (sum >= m) sum -= field[low++];
        else if (high == n) break;
        else sum += field[high++];
        if (sum == m) result += 1;
    } cout << result;
    return 0;
}