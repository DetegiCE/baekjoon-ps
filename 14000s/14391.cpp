#include<bits/stdc++.h>
using namespace std;

int n, m;
int ar[5][5];
int mx;

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            scanf("%1d", &ar[i][j]);
        }
    }
    
    for(int i=0 ; i<(1<<(n*m)) ; i++) {
        int tmp[5][5];
        int dir[5][5]; // 0 가로 1 세로
        int p = 0;
        for(int j=0 ; j<n ; j++) {
            for(int k=0 ; k<m ; k++) {
                dir[j][k] = !!(i & (1<<p));
                p++;
            }
        }
        
        int sum = 0;
        for(int j=0 ; j<n ; j++) {
            for(int k=0 ; k<m ; k++) {
                if(j == 0 && k == 0) tmp[j][k] = ar[j][k];
                else {
                    if(dir[j][k] == 0) {
                        if(k > 0 && dir[j][k-1] == 0) tmp[j][k] = tmp[j][k-1]*10+ar[j][k];
                        else if(k == 0) tmp[j][k] = ar[j][k];
                        else tmp[j][k] = ar[j][k];
                    }
                    else {
                        if(j > 0 && dir[j-1][k] == 0) tmp[j][k] = ar[j][k];
                        else if(j == 0) tmp[j][k] = ar[j][k];
                        else tmp[j][k] = tmp[j-1][k]*10+ar[j][k];
                    }
                }
                
                if(j == n-1 && k == m-1) sum += tmp[j][k];
                else {
                    if(dir[j][k] == 0) {
                        if(k < m-1 && dir[j][k+1] == 1) sum += tmp[j][k];
                        else if(k == m-1) sum += tmp[j][k];
                    }
                    else {
                        if(j < n-1 && dir[j+1][k] == 0) sum += tmp[j][k];
                        else if(j == n-1) sum += tmp[j][k];
                    }
                }
            }
        }
        // printf("[%d %d]\n", i, sum);
        // for(int j=0 ; j<n ; j++) {
        //     for(int k=0 ; k<m ; k++) {
        //         printf("%d ", tmp[j][k]);
        //     }
        //     puts("");
        // }
        // puts("");
        mx = max(mx, sum);
    }
    printf("%d", mx);
}