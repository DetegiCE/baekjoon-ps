#include<cstdio>
#include<bitset>
using namespace std;

int n, k, scores[152], acc[152], score[152][152];
int maxscore;
bitset<1135000> dp[152];

int main()
{
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++) {
        scanf("%d", &scores[i]);
        acc[i] = acc[i-1] + scores[i];
    }
    for(int i=1 ; i<=n ; i++) {
        for(int j=i ; j<=n ; j++) {
            score[i][j] = score[i][j-1] + acc[j] - acc[i-1];
        }
    }
    scanf("%d", &k);

    if(k > score[1][n]) {
        printf("%d", k);
        return 0;
    }

    dp[0].set(0, 1);
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=i+1 ; j++) {
            // j ~ i 번까지 연속으로 맞춘 경우
            if(j <= 2) dp[i].set(score[j][i], 1);
            else dp[i] |= (dp[j-2] << score[j][i]);
        }
    }
    int ans;
    for(ans = k ; dp[n].test(ans) ; ans++);
    printf("%d", ans);
}   