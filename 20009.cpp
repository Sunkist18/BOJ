#include <queue>
#include <cstring>
#include <map>
#include <iostream>
#include <string>

#define int long long
using namespace std;
typedef pair<int, int> pii;

int n;
string var;

int priority[400][400];

map<int, string> node_to_name;
map<string, int> name_to_node;
int man_pair[200];
map<int, queue<int>> girl_queue;

void Input() {
    memset(man_pair, -1, sizeof(man_pair));
    cin >> n;

    // man input
    for (int i = 0; i < 2 * n; i++) {
        cin >> var;
        node_to_name[i] = var;
        name_to_node[var] = i;
    }
    int from_node, to_node;
    for (int i = 0; i < n; i++) {
        cin >> var;
        from_node = name_to_node[var];
        for (int j = 1; j <= n; j++) {
            cin >> var;
            to_node = name_to_node[var];
            priority[from_node][to_node] = j;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> var;
        from_node = name_to_node[var];
        for (int j = 1; j <= n; j++) {
            cin >> var;
            girl_queue[from_node].push(name_to_node[var]);
        }
    }
}

int propose(int girl, int boy) {
    if (man_pair[boy] != -1) {
        // he already has gf.
        if (priority[boy][man_pair[boy]] < priority[boy][girl]) {
            // he love his gf more than you. fuck off.
            return girl;
        }
        else {
            // omg he choose other girl Xp
            int ret = man_pair[boy];
            man_pair[boy] = girl;
            return ret;
        }
    }
    // he doesn't have any gf, so. you win.
    man_pair[boy] = girl;
    return -1;
}

void Solve() {
    queue<int> que;
    // Push woman nodes
    for (int i = n; i < 2 * n; i++)
        que.push(i);

    while (!que.empty()) {
        int girl = que.front();
        que.pop();
        int boy = girl_queue[girl].front();
        girl_queue[girl].pop();
        int remain_girl = propose(girl, boy);
        if (remain_girl == -1)
            continue;
        que.push(remain_girl);
    }
}



int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Solve();
    for (int i = 0; i < n; i++)
        cout << node_to_name[i] << ' ' << node_to_name[man_pair[i]] << '\n';
    return 0;
}