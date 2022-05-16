#include<cstdio>

char st[500002][12];
int dp[500002][12];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0 ; i<n ; i++) {
        scanf("%s", st[i]);
    }
    for(int i=1 ; i<n ; i++) {
        for(int j=0; j<k ; j++) {
            if(!j) {
                if(st[i][j] != st[i-1][j]) {
                    dp[i][j] = dp[i-1][j] + 1;
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
            else {
                if(st[i][j] != st[i-1][j]) {
                    if(dp[i][j-1] == dp[i-1][j-1]) dp[i][j] = dp[i-1][j-1];
                    else dp[i][j] = dp[i][j-1];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    printf("%d", dp[n-1][k-1]/2);
}