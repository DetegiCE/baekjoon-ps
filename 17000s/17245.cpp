#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[10000007];
ll c[10000007];
ll sum;
ll mx;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll t;
            cin >> t;
            a[t]++;
            sum += t;
            mx = max(mx, t);
        }
    }
    if (sum == 0) {
        cout << 0;
        return 0;
    }
    a[0] = 0;
    for (int i = mx; i >= 1; i--) {
        c[i] = c[i + 1] + a[i];
    }
    for (int i = 1; i <= mx; i++) {
        a[i] = a[i - 1] + c[i];
    }
    for (int i = 1; i <= mx; i++) {
        if (a[i] >= (sum + 1) / 2) {
            cout << i;
            return 0;
        }
    }
}