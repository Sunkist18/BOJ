#include <bits/stdc++.h>

using namespace std;

bitset<100000> bit_a;
bitset<100000> bit_b;

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> bit_a >> bit_b;
    cout << (bit_a & bit_b) << '\n'<< (bit_a | bit_b) << '\n'<< (bit_a ^ bit_b) << '\n'<< (bit_a.flip()) << '\n'<< (bit_b.flip()) << '\n';
    return 0;
}