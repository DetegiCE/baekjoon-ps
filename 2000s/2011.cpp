#include<cstdio>
#include<cstring>

char pass[5002];
int plen;
int dp[5002];

int main()
{
    scanf("%s", &pass[1]);
    plen = strlen(&pass[1]);
    if(pass[1] == '0') {
        puts("0");
        return 0;
    }
    dp[1] = 1;
    if((pass[1] == '1' && pass[2] >= '1' && pass[2] <= '9') || (pass[1] == '2' && pass[2] >= '1' && pass[2] <= '6')) dp[2] = 2;
    else if(pass[2] == '0' && pass[1] >= '3') {
        puts("0");
        return 0;
    }
    else dp[2] = 1;
    for(int i=3 ; i<=plen ; i++) {
        if(pass[i] >= '1' && pass[i] <= '9') dp[i] = dp[i-1];
        else {
            if(pass[i-1] == '1' || pass[i-1] == '2') {
                dp[i] = dp[i-2];
                continue;
            }
            else {
                puts("0");
                return 0;
            }
        }
        if(pass[i-1] == '1' || (pass[i-1] == '2' && pass[i] >= '0' && pass[i] <= '6')) {
            dp[i] += dp[i-2];
        }
        dp[i] %= 1000000;
    }
    //for(int i=1 ; i<=plen ; i++) printf("%d ", dp[i]); puts("");
    printf("%d\n", dp[plen] % 1000000);
}