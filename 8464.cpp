#include <bits/stdc++.h>

#define int long long
using namespace std;
#define MAX 1000000

// U :: mobius function
// U(n) = { -1, 0, 1 }
int U[MAX + 1], k;

int count(int N) {
    int result = 0;
    for (int i = 1; i * i <= N; i++)
        result += U[i] * (N / (i * i));
    return N - result;
}

#undef int
int main() {
#define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k;
    // initialization
    U[1] = 1;
    for (int N = 1; N <= MAX; N++) {
        for (int i = N + N; i <= MAX; i += N)
            U[i] -= U[N];
    }
    int low = 1, high = 1000000000000 + 1;
    while (low + 1 < high) {
        int mid = (low + high) / 2;
        if (count(mid) < k)
            low = mid;
        else high = mid;
    }
    cout << high << '\n';
    return 0;
}