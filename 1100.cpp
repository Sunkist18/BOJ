// https://www.acmicpc.net/problem/1100.cpp

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
vector<string> field;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string var;
    int result = 0;
    while (cin >> var) field.push_back(var);
    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) result += (field[i][j] == 'F' and (i + j) % 2 == 0);
    cout << result;
    return 0;
}