#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 98765432

int n;
int dst[103][103];

void floyd() {
    for(int k=1 ; k<=n ; k++) {
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n ; j++) {
                if(dst[i][j] > dst[i][k] + dst[k][j]) {
                    dst[i][j] = dst[i][k] + dst[k][j];
                }
            }
        }
    }
}

int main()
{
    INP;
    
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            dst[i][j] = INF;
        }
    }
    for(int i=1 ; i<=n-1 ; i++) {
        int t;
        cin >> t;
        for(int j=0 ; j<t ; j++) {
            int s;
            cin >> s;
            dst[i][s] = 1;
        }
    }
    floyd();
    for(int i=1 ; i<=n ; i++) {
        if(dst[1][i] !=INF && dst[i][i] != INF) {
            cout << "CYCLE";
            return 0;
        }
    }
    cout << "NO CYCLE";
}