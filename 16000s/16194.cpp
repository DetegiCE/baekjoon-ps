#include<cstdio>

#define MIN(A,B) (A>B?B:A)
#define MIN3(A,B,C) (MIN(A,B)>C?C:MIN(A,B))

int n;
int ar[1001];
int dp[1001][1001];
// i번 카드팩까지 이용해서 j개 구매하는데 필요한 금액
/*
dp[i][j] = MIN(dp[i-1][j-i] + ar[i], dp[i-1][j], dp[i][j-i] + ar[i])
*/

int main()
{
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++) {
        scanf("%d", &ar[i]);
    }
    for(int i=1 ; i<=n ; i++) dp[1][i] = ar[1] * i;
    for(int i=2 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            if(i > j) dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = MIN3(dp[i-1][j-i]+ar[i], dp[i-1][j], dp[i][j-i]+ar[i]);
            }
        }
    }
    printf("%d", dp[n][n]);
}