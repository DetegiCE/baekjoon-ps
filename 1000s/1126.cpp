#include<cstdio>

#define ABS(A) (A>0?A:(-A))

int n, tsum = 0;
int dp[55][500005];

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<=n ; i++) {
        for(int j=0 ; j<=500000 ; j++) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    for(int i=1 ; i<=n ; i++) {
        int t;
        scanf("%d", &t);
        for(int j=0 ; j<=tsum ; j++) {
            if(dp[i-1][j] != -1) {
                dp[i][j] = dp[i-1][j];
                dp[i][j+t] = dp[i-1][j] + 1;
                dp[i][ABS(j-t)] = dp[i-1][j] + 1;
            }
        }
        tsum += t;
    }
    if(dp[n][0] > 0) printf("%d", tsum/2);
    else puts("-1");
}