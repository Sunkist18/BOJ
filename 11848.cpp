#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int, int> pii;
int visited[300000 + 1];
int n, m, s, args1, args2;
priority_queue<pii> music;
priority_queue<pii> sport;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++) {
        cin >> args1 >> args2;
        music.push({args1, i});
        sport.push({args2, i});
    }
    int result = 0;
    while (m > 0 or s > 0) {
        pii max_pii = {0, -1};
        bool isMusic = false;
        if (m) {
            if (music.top().first > max_pii.first) {
                max_pii = music.top();
                isMusic = true;
            }
        } else if (sport.top().first > max_pii.first)
            max_pii = sport.top();
        if (!visited[max_pii.second]) {
            visited[max_pii.second] = max_pii.first;
            result += max_pii.first;
            if (isMusic) {
                music.pop();
                m--;
            } else {
                sport.pop();
                s--;
            }
        } else {
            if (isMusic) {
                music.pop();
                // front : sport 손해 back : music 손해
                if (visited[max_pii.second] - sport.top().first < max_pii.first - music.top().first) {
                    result -= visited[max_pii.second];
                    visited[max_pii.second] = max_pii.first;
                    result += visited[max_pii.second];
                    m--;
                    s++;
                }
            } else {
                sport.pop();
                if (visited[max_pii.second] - music.top().first < max_pii.first - sport.top().first) {
                    result -= visited[max_pii.second];
                    visited[max_pii.second] = max_pii.first;
                    result += visited[max_pii.second];
                    s--;
                    m++;
                }
            }
        }
    }
    cout << result;
    return 0;
}