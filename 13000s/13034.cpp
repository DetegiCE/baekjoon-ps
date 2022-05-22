#include<cstdio>

int n;
int dp[1001];
bool chk[16];

int main()
{
    scanf("%d", &n);
    dp[0]=dp[1]=0;
    dp[2]=dp[3]=1;
    for(int i=4 ; i<=n ; i++) {
        for(int j=0 ; j<16 ; j++) chk[j] = false;
        for(int j=0 ; j<=i-2 ; j++) {
            int tmp = dp[j] ^ dp[i-2-j];
            chk[tmp] = true;
        }
        for(int j=0 ; j<16 ; j++) {
            if(!chk[j]) {
                dp[i] = j;
                break;
            }
        }
    }
    printf("%d", dp[n] == 0 ? 2 : 1);
}