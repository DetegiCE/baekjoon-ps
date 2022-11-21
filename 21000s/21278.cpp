#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define MP(A,B) make_pair(A,B)
#define INF 100000000
typedef pair<int,int> pii;

int n, m;
int dst[102][102];

int main() 
{
    INP;
    
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
    for(int k=1 ; k<=n ; k++) {
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n ; j++) {
                if(dst[i][j] > dst[i][k] + dst[k][j]) {
                    dst[i][j] = dst[i][k] + dst[k][j];
                }
            }
        }
    }
    
    int mnv = INF;
    int mna, mnb;
    for(int i=1 ; i<=n ; i++) {
        for(int j=i+1 ; j<=n ; j++) {
            int ts = 0;
            for(int k=1 ; k<=n ; k++) {
                if(i == k || j == k) continue;
                ts += min(dst[i][k], dst[j][k]);
            }
            if(ts < mnv) {
                mnv = ts;
                mna = i;
                mnb = j;
            }
        }
    }
    
    cout << mna << ' ' << mnb << ' ' << mnv*2;
}