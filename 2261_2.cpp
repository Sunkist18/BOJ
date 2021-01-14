#include <bits/stdc++.h>

using namespace std;

class Point {
public:
    int x, y;
};

int compare_x(const void *a, const void *b) {
    auto *p1 = (Point *) a;
    auto *p2 = (Point *) b;
    return (p1->x - p2->x);
}

int compare_y(const void *a, const void *b) {

    auto *p1 = (Point *) a;
    auto *p2 = (Point *) b;
    return (p1->y - p2->y);
}

int dist_pow(Point p1, Point p2) {
    int dist = (p1.x - p2.x) * (p1.x - p2.x) +
               (p1.y - p2.y) * (p1.y - p2.y);
    if (dist == 0) {
        cout << '0';
        exit(0);
    }
    return dist;
}

int bruteForce (Point P[], int n) {
    int min_value = INT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(dist_pow(P[i], P[j]) < min_value) {
                min_value = dist_pow(P[i], P[j]);
            }
        }
    }
    return min_value;
}

int stripClosest(Point strip[], int size, int dist) {
    int min_value = dist;
    qsort(strip, size, sizeof(Point), compare_y);

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min_value; j++) {
            if (dist_pow(strip[i], strip[j]) < min_value)
                min_value = dist_pow(strip[i], strip[j]);
        }
    }
    return min_value;
}

int closestPair(Point P[], int n) {
    if (n <= 3)
        return bruteForce(P, n);

    int mid = n / 2;
    Point midPoint = P[mid];

    int dl = closestPair(P, mid);
    int dr = closestPair(P + mid, n - mid);
    int d = min(dl, dr);
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;
    }

    return min(d, stripClosest(strip, j, d));
}

int main() {
    int n, x, y;
    cin >> n;
    Point P[n];
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        P[i].x = x;
        P[i].y = y;
    }

    qsort(P, n, sizeof(Point), compare_x);
    cout << closestPair(P, n);
}