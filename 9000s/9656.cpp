#include<cstdio>

int main()
{
    int n, dp[1001];
    bool chk[16];
    scanf("%d", &n);
    dp[1]=dp[3]=0;
    dp[0]=dp[2]=1;
    for(int i=4 ; i<=n ; i++) {
        for(int j=0 ; j<16 ; j++) chk[j] = false;
        chk[dp[i-1] ^ dp[1]] = true;
        chk[dp[i-3] ^ dp[3]] = true;
        for(int j=0 ; j<16 ; j++) {
            if(!chk[j]) {
                dp[i] = j;
                break;
            }
        }
    }
    printf("%s", dp[n] == 0 ? "CY" : "SK");
}