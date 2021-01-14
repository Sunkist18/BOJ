#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
deque<pii> balloons;
int n, args;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> args;
        balloons.emplace_back(i, args);
    }
    while (!balloons.empty()) {
        pii balloon = balloons.front();
        cout << balloon.first << ' ';
        balloons.pop_front();
        for (int i = 1; i < balloon.second; i++) {
            balloons.push_back(balloons.front());
            balloons.pop_front();
        }
        for (int i = 0; i > balloon.second; i--) {
            balloons.push_front(balloons.back());
            balloons.pop_back();
        }
    }
    return 0;
}