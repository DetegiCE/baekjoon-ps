#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <vector>
using namespace std;

#define PI 3.14159265358979323846

typedef long long int ll;
typedef complex<double> cd;

void fft(vector<cd> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
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
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());

    int n = 1, m = a.size() + b.size() - 1;
    while (n < m) n <<= 1;

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);

    ans.resize(n);
    for (int i = 0; i < n; i++)
        ans[i] = int(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}

vector<ll> primes;

void makePrime(ll n) {
    int flag = 0;
    for(ll i=3 ; i<=n ; i+=2) {
        flag = 0;
        for(ll j=2 ; j*j<=i ; j++) {
            if(i%j == 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) primes.push_back(i);
    }
}

int main() {
    int n;
    makePrime(1e6);
    vector<ll> ans;
    vector<ll> a(1000004), b(1000004);
    b[4] = 1;
    for(int i=0 ; i<primes.size() ; i++) {
        a[primes[i]] = 1;
        if(primes[i] * 2 <= 1e6) b[primes[i] * 2] = 1;
    }   
    multiply(a, b, ans);

    int m, cnt = 0;
    scanf("%d", &m);
    while(m--) {
        int t;
        scanf("%d", &t);
        printf("%lld\n", ans[t]);
    }
}