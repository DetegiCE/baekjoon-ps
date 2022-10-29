#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 98765432
#define NMX 100

int n;
int dst[NMX+2][NMX+2];

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
    
    int m;
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            dst[i][j] = INF;
        }
        dst[i][i] = 0;
    }
    for(int i=0 ; i<m ; i++) {
        int a, b;
        cin >> a >> b;
        dst[a][b] = dst[b][a] = 1;
    }
    floyd();
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            if(dst[i][j] > 6) {
                cout << "Big World!";
                return 0;
            }
        }
    }
    cout << "Small World!";
}