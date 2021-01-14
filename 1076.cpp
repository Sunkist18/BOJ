#include <bits/stdc++.h>

using namespace std;
typedef pair<long long, long long> pll;
map<string, pll> field;
string a, b, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    field["black"] = {0, 1};        field["brown"] = {1, 10};
    field["red"] = {2, 100};        field["orange"] = {3, 1000};
    field["yellow"] = {4, 10000};   field["green"] = {5, 100000};
    field["blue"] = {6, 1000000};   field["violet"] = {7, 10000000};
    field["grey"] = {8, 100000000}; field["white"] = {9, 1000000000};

    cin >> a >> b >> c;
    cout << (field[a].first * 10 + field[b].first) * field[c].second;
    return 0;
}