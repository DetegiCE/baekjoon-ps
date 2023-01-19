#include<bits/stdc++.h>
using namespace std;
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)

int n, m, mn=10004;
int pos[102][102];
int acc[102][102];

int sums(int stx, int sty, int enx, int eny) {
    return acc[enx][eny] - acc[enx][sty-1] - acc[stx-1][eny] + acc[stx-1][sty-1];
}

void check(int garo) {
    int sero = m / garo;
    // cout << garo << ' ' << sero << '\n';
    for(int i=1 ; i<=n-garo+1 ; i++) {
        for(int j=1 ; j<=n-sero+1 ; j++) {
            int s = sums(i, j, i+garo-1, j+sero-1);
            // cout << i-1 << ' ' << j-1 << ' ' << i+garo-1 << ' ' << j+sero-1 << ' ' << s << '\n';
            mn = min(mn, m-s);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i=0 ; i<m ; i++) {
        int r, c;
        cin >> r >> c;
        pos[r][c]=1;
    }
    // for(int i=1 ; i<=n ; i++) {
    //     for(int j=1 ; j<=n ; j++) {
    //         cout << pos[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            acc[i][j] = acc[i-1][j] + acc[i][j-1] - acc[i-1][j-1] + pos[i][j];
        }
    }
    for(int i=1 ; i<=m ; i++) {
        if(m % i == 0) {
            check(i);
        }
    }
    cout << mn;
}

