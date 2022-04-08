#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <vector>
using namespace std;

#define PI 3.14159265358979323846
#define MAX 2097152

typedef long long int ll;
typedef long double ld;
typedef complex<ld> cld;
vector<ll> a(MAX, 0), b(MAX, 0);

void fft(vector<cld> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        ld ang = 2 * PI / len * (invert ? -1 : 1);
        cld wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cld w(1);
            for (int j = 0; j < len / 2; j++) {
                cld u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (int i = 0; i < n; i++) a[i] /= n;
    }
}

void multiply(vector<ll> &a, vector<ll> &b, vector<ll> &ans) {
    vector<cld> fa(a.begin(), a.end()), fb(b.begin(), b.end());

    int n = 1;
    while (n < max(a.size(), b.size())) n <<= 1;

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);

    ans.resize(n);
    for (int i = 0; i < n; i++)
        ans[i] = ll(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i <= m; i++) {
        scanf("%lld", &b[i]);
    }

    vector<ll> ans1, ans2, ans3, ans4;
    vector<ll> tempa, tempb;

    tempa = a, tempb = b;
    for (auto &i : tempa) i &= ((1 << 10) - 1);
    for (auto &i : tempb) i &= ((1 << 10) - 1);
    multiply(tempa, tempb, ans4);

    tempa = a, tempb = b;
    for (auto &i : tempa) i >>= 10;
    for (auto &i : tempb) i &= ((1 << 10) - 1);
    multiply(tempa, tempb, ans3);

    tempa = a, tempb = b;
    for (auto &i : tempa) i &= ((1 << 10) - 1);
    for (auto &i : tempb) i >>= 10;
    multiply(tempa, tempb, ans2);

    tempa = a, tempb = b;
    for (auto &i : tempa) i >>= 10;
    for (auto &i : tempb) i >>= 10;
    multiply(tempa, tempb, ans1);

    ll res = 0;
    for (int i = 0; i <= n + m; i++) {
        res ^= (ans1[i] << 20) + ((ans2[i] + ans3[i]) << 10) + ans4[i];
    }
    printf("%lld", res);
}