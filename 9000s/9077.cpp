#include <bits/stdc++.h>
using namespace std;

bool mp[10001][10001];
int sm[10001][10001];

void f() {
    int n;
    cin >> n;
    for(int i=0 ; i<=10000 ; i++) {
        for(int j=0 ; j<=10000 ; j++) {
            mp[i][j] = sm[i][j] = 0;
        }
    }
    for(int i=0 ; i<n ; i++) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
    }
    sm[0][0] = mp[0][0];
    for(int i=1 ; i<=10000 ; i++) {
        sm[0][i] = sm[0][i-1] + mp[0][i];
        sm[i][0] = sm[i-1][0] + mp[i][0];
    }
    for(int i=1 ; i<=10000 ; i++) {
        for(int j=1 ; j<=10000 ; j++) {
            sm[i][j] = sm[i-1][j] + sm[i][j-1] - sm[i-1][j-1] + mp[i][j];
        }
    }
    int mx = sm[10][10];
    for(int i=11 ; i<=10000 ; i++) {
        mx = max(mx, sm[i][10] - sm[i-11][10]);
        mx = max(mx, sm[10][i] - sm[10][i-11]);
    }
    for(int i=12 ; i<=10000 ; i++) {
        for(int j=12 ; j<=10000 ; j++) {
            mx = max(mx, sm[i][j] - sm[i-11][j] - sm[i][j-11] + sm[i-11][j-11]);
        }
    }
    cout << mx << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        f();
    }
}
