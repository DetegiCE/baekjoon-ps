#include <cstdio>

int n;
int ar[17][17];
int dp[17][17][3];  // 0 garo 1 sero 2 daegak

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &ar[i][j]);
        }
    }
    dp[0][1][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (!i && !(j - 1)) continue;
            if (ar[i][j] != 1) {
                dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
                if (i) dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
                if (i && ar[i][j - 1] != 1 && ar[i - 1][j] != 1)
                    dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] +
                                  dp[i - 1][j - 1][2];
            }
        }
    }

    printf("%d",
           dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2]);
}