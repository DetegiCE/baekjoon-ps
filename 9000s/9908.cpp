#include <bits/stdc++.h>
using namespace std;

int a[52][52];
int n, m;
int c, mx;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    cin >> c;
    for(int i=0 ; i<c ; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            for(int k=i ; k<=n ; k++) {
                for(int l=j ; l<=m ; l++) {
                    int sz = (k-i+1) * (l-j+1);
                    int cnt = 0;
                    for(int p=i ; p<=k ; p++) {
                        for(int q=j ; q<=l ; q++) {
                            cnt += a[p][q];
                        }
                    }
                    if(cnt == 0) {
                        mx = max(mx, sz);
                    }
                }
            }
        }
    }
    cout << mx;
}