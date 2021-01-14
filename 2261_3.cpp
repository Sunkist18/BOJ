#include <bits/stdc++.h>

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

typedef struct Point {
    public:
    int x, y;
} Point;

int cmp_x(const void *a, const void *b) {
    Point x = *(Point *) a;
    Point y = *(Point *) b;
    return (x.x - y.x);
}

int cmp_y(const void *a, const void *b) {
    Point x = *(Point *) a;
    Point y = *(Point *) b;
    return (x.y - y.y);
}

int distance(Point x, Point y) {
    return (x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y);
}

int brute_force(Point p[], int n) {
    int result = INT_MAX;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            result = min(result, distance(p[i], p[j]));
    return result;
}


int closest_pair(Point p[], int n) {
    if (n <= 3)
        return brute_force(p, n);
    int mid = n / 2;
    Point midPoint = p[mid];
    int dist_1 = closest_pair(p, mid);
    int dist_2 = closest_pair(p + mid, n - mid);
    int dist = min(dist_1, dist_2);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(p[i].x - midPoint.x) < dist)
            strip[j] = p[i], j++;

    int size = j;
    qsort(p, size, sizeof(Point), cmp_y);
    for (int i = 0; i < size; ++i)
        for (int jj = i + 1; jj < size && (strip[jj].y - strip[i].y) < dist; ++jj)
            if (distance(strip[i],strip[jj]) < dist)
                dist = distance(strip[i], strip[jj]);
    return dist;
}

int n, x, y;
Point field[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        field[i] = {x, y};
    }

    qsort(field, n, sizeof(Point), cmp_x);
    cout << closest_pair(field, n);
    return 0;
}