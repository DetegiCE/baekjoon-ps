#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

int mapp[1002][1002];
int n, px, py, sx, sy;

int main()
{
    INP;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cin >> mapp[i][j];
            if(mapp[i][j] == 5) {
                px = j;
                py = i;
            }
            if(mapp[i][j] == 2) {
                sx = j;
                sy = i;
            }
        }
    }
    int dst = (px-sx)*(px-sx)+(py-sy)*(py-sy);
    if(dst < 25) {
        cout << 0;
    }
    else {
        int cnt = 0;
        for(int i=min(py,sy) ; i<=max(py,sy) ; i++) {
            for(int j=min(px,sx) ; j<=max(px,sx) ; j++) {
                if(mapp[i][j] == 1) cnt++;
            }
        }
        if(cnt >= 3) cout << 1;
        else cout << 0;
    }
}