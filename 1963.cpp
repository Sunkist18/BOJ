// https://www.acmicpc.net/problem/1963.cpp

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

int t;
bool isPrime[10000];
bool isVisit[10000];

string bfs(int from, int to) {
    isVisit[from] = true;
    queue<pii> que;
    que.emplace(from, 0);
    while (!que.empty()) {
        int here, cost;
        tie(here, cost) = que.front();
        que.pop();
        if (here == to) return to_string(cost);
        string num[4];
        for (int i = 0; i < 4; i++) num[i] = to_string(here).at(i);
        for (int i = 0; i < 10; i++) {
            int nums[] = {stoi(to_string(i) + num[1] + num[2] + num[3]),
                          stoi(num[0] + to_string(i) + num[2] + num[3]),
                          stoi(num[0] + num[1] + to_string(i) + num[3]),
                          stoi(num[0] + num[1] + num[2] + to_string(i))};
            for (int there: nums) {
                if (isPrime[there] and !isVisit[there] and 1000 <= there and there < 10000) {
                    isVisit[there] = true;
                    que.emplace(there, cost + 1);
                }
            }
        }
    }
    return "Impossible";
}

void solve() {
    int from, to;
    cin >> from >> to;
    memset(isVisit, false, sizeof(isVisit));
    cout << bfs(from, to) << '\n';
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;

    memset(isPrime, true, sizeof(isPrime));
    for (int i = 2; i < 10000; i++)
        if (isPrime[i])
            for (int j = i + i; j < 10000; j += i)
                isPrime[j] = false;

    while (t--)
        solve();
    return 0;
}