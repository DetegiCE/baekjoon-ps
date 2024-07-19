#include <bits/stdc++.h>
using namespace std;

int n, k, m;
int point[30][300][300];
int mk[300][300];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> k >> m;
    for(int i=0 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        point[0][i+1][a] = 1;
        point[0][i+1][b] = 1;
    }
    
    for(int l=1 ; l<=21 ; l++) {
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n ; j++) {
                for(int p=1 ; p<=n ; p++) {
                    point[l][i][j] += point[l-1][i][p] * point[l-1][p][j];
                }
            }
        }
    }
    
    int cnt = 0;
    for(int l=21 ; l>=0 ; l--) {
        if(k & (1<<l)) {
            if(cnt == 0) {
                for(int i=1 ; i<=n ; i++) {
                    for(int j=1 ; j<=n ; j++) {
                        mk[i][j] = point[l][i][j];
                    }
                }
                cnt++;
            }
            else {
                int tmp[300][300];
                for(int i=1 ; i<=n ; i++) {
                    for(int j=1 ; j<=n ; j++) {
                        tmp[i][j] = 0;
                        for(int p=1 ; p<=n ; p++) {
                            tmp[i][j] += mk[i][p] * point[l][p][j];
                        }
                    }
                }
                for(int i=1 ; i<=n ; i++) {
                    for(int j=1 ; j<=n ; j++) {
                        mk[i][j] = tmp[i][j];
                    }
                }
            }
        }
    }
    
    for(int i=0 ; i<m ; i++) {
        int a, b;
        cin >> a >> b;
        if(mk[a][b]) cout << "death\n";
        else cout << "life\n";
    }
}
