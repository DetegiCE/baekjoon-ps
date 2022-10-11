#include <bits/stdc++.h>
using namespace std;

typedef struct timess {
    double deg;
    int h;
    int m;

    timess(double deg, int h, int m) : deg(deg), h(h), m(m) {}
} TIMES;

bool compare(TIMES a, TIMES b) {
    if (a.deg == b.deg) {
        if (a.h == b.h) return a.m < b.m;
        return a.h < b.h;
    }
    return a.deg < b.deg;
}

vector<TIMES> v;

void sol() {
    v.clear();
    for (int i = 0; i < 5; i++) {
        int a, b;
        scanf("%d:%d", &a, &b);
        double hdeg = 30.0 * a + 0.5 * b + 360.0;
        double mdeg = 6.0 * b;

        double degs = abs(hdeg - mdeg);
        if (degs >= 360) degs -= 360;
        if (degs >= 360) degs -= 360;
        if (degs >= 180) degs = 360 - degs;

        v.emplace_back(degs, a, b);
    }
    sort(v.begin(), v.end(), compare);
    printf("%02d:%02d\n", v[2].h, v[2].m);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        sol();
    }
}