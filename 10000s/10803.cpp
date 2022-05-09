#include<cstdio>

#define MIN(A, B) ((A)>(B)?(B):(A))

int dp[10001][101];

int square(int n, int m) {
    if(n < m) int t = n, n = m, m = t;
    if(n % m == 0) return n / m;
    if(n == m) return 1;

    if(dp[n][m] != 10000001) return dp[n][m];

    if(n >= m * 3) dp[n][m] = MIN(dp[n][m], square(n-m, m) + 1);
    else {
        for(int i=1 ; i<=n/2 ; i++) 
            dp[n][m] = MIN(dp[n][m], square(n-i, m) + square(i, m));
        for(int i=1 ; i<=m/2 ; i++)
            dp[n][m] = MIN(dp[n][m], square(n, m-i) + square(n, i));
    }
    return dp[n][m];
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            dp[i][j] = 10000001;
        }
    }
    printf("%d", square(n, m));
}