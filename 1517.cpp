#include <bits/stdc++.h>

#define int long long
using namespace std;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)

int sum() { return 0; }

template<typename T, typename... Args>
auto sum(T a, Args... args) { return a + sum(args...); }

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}

template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

typedef pair<int, int> pii;

int arr[500001], sorted[500001], cnt = 0, n;

void merge(int left, int mid, int right) {
    int low = left;
    int k = left;
    int high = mid + 1;
    while (low <= mid && high <= right) {
        if (arr[low] <= arr[high])
            sorted[k++] = arr[low++];
        else {
            cnt += mid - low + 1;
            sorted[k++] = arr[high++];
        }
    }
    if (low <= mid) {
        for (int i = low; i <= mid; i++)
            sorted[k++] = arr[i];
    } else {
        for (int i = high; i <= right; i++)
            sorted[k++] = arr[i];
    }
    for (int i = left; i <= right; i++)
        arr[i] = sorted[i];
}


void merge_sort(int left, int right) {
    if (left < right) {
        int m = (left + right) / 2;
        merge_sort(left, m);
        merge_sort(m + 1, right);
        merge(left, m, right);
    }
}

int32_t main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    merge_sort(1, n);
    cout << cnt << '\n';
}