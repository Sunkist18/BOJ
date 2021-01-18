// https://www.acmicpc.net/problem/2443.cpp

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
int n, sum, var;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (cin >> var) sum += var;
    cout << var;
    return 0;
}