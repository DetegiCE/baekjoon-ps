#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cnt = 0;
    while(1) {
        int n;
        scanf("%d", &n);
        if(n == 0) break;
        
        int a[21], b[21];
        for(int i=0 ; i<n ; i++) {
            scanf("%d", &a[i]);
        }
        
        int flg = 0;
        for(int i=1 ; i<=1001 ; i++) {
            for(int j=0 ; j<n-1 ; j++) {
                b[j] = abs(a[j]-a[j+1]);
            }
            b[n-1] = abs(a[0]-a[n-1]);
            
            int scnt = 0;
            for(int j=0 ; j<n-1 ; j++) {
                if(a[j] == a[j+1]) scnt++;
                else break;
            }
            for(int j=0 ; j<n ; j++) a[j] = b[j];
            if(scnt == n-1) {
                printf("Case %d: %d iterations\n", ++cnt, i-1);
                flg = 1;
                break;
            }
        }
        if(flg == 0) {
            printf("Case %d: not attained\n", ++cnt);
        }
        
    }
}