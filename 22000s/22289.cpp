#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
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

int main() {
    int n;
    vector<ll> ans;
    vector<ll> a, b;
    char aa[1000004], bb[1000004];
    int aalen, bblen;
    scanf("%s %s", aa, bb);
    aalen = strlen(aa);
    bblen = strlen(bb);
    for(int i=aalen-1 ; i>=0 ; i--) {
        a.push_back(aa[i]-'0');
    }
    for(int i=bblen-1 ; i>=0 ; i--) {
        b.push_back(bb[i]-'0');
    }
    multiply(a, b, ans);

    stack<ll> st;
    int up = 0;
    for(int i=0 ; i<ans.size() ; i++) {
        //printf("[%lld]", ans[i]);
        if(up > 0) ans[i] += up;
        if(ans[i] >= 10) {
            up = ans[i] / 10;
            st.push(ans[i] % 10);
        }
        else {
            up = 0;
            st.push(ans[i]);
        }
    }
    if(up > 0) st.push(up);

    int zeroflag = 0;
    while(!st.empty() && st.top() == 0) st.pop();
    while(!st.empty()) {
        printf("%lld", st.top());
        st.pop();
        zeroflag = 1;
    }
    if(zeroflag == 0) puts("0");
}