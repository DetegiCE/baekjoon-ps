#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int dp[1001][31];
int mx;

int main()
{
    int t, w;
    scanf("%d %d", &t, &w);
    for(int i=0 ; i<t ; i++) {
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }

    // start = 1
    if(v[0] == 1) dp[0][0] = 1;
    for(int i=1 ; i<t ; i++) {
        dp[0][i] = dp[0][i-1] + (v[i]==1?1:0);
    }
    mx = dp[0][t-1];
    for(int i=1 ; i<=w ; i++) {
        dp[i][i] = dp[i-1][i-1] + (i%2==v[i]%2?0:1);
        for(int j=i ; j<t ; j++) {
            if(i % 2 == 0) { // at 1
                if(v[j] == 1) dp[i][j] = max(dp[i-1][j-1],dp[i][j-1]) + 1;
                else dp[i][j] = max(dp[i-1][j-1],dp[i][j-1]);
            }
            else { // at 2
                if(v[j] == 2) dp[i][j] = max(dp[i-1][j-1],dp[i][j-1]) + 1;
                else dp[i][j] = max(dp[i-1][j-1],dp[i][j-1]);
            }

            if(j == t-1) {
                printf("%d => %d\n", i, dp[i][j]);
                mx = max(mx, dp[i][j]);
            }
        }
    }


    // start = 2
    w--;
    if(v[0] == 2) dp[0][0] = 1;
    for(int i=1 ; i<t ; i++) {
        dp[0][i] = dp[0][i-1] + (v[i]==2?1:0);
    }
    mx = max(mx, dp[0][t-1]);
    for(int i=1 ; i<=w ; i++) {
        dp[i][i] = dp[i-1][i-1] + (i%2!=v[i]%2?0:1);
        for(int j=i ; j<t ; j++) {
            if(i % 2 == 1) { // at 1
                if(v[j] == 1) dp[i][j] = max(dp[i-1][j-1],dp[i][j-1]) + 1;
                else dp[i][j] = max(dp[i-1][j-1],dp[i][j-1]);
            }
            else { // at 2
                if(v[j] == 2) dp[i][j] = max(dp[i-1][j-1],dp[i][j-1]) + 1;
                else dp[i][j] = max(dp[i-1][j-1],dp[i][j-1]);
            }

            if(j == t-1) {
                printf("%d => %d\n", i, dp[i][j]);
                mx = max(mx, dp[i][j]);
            }
        }
    }
    // for(int i=0 ; i<=w ; i++) {
    //     for(int j=0 ; j<t ; j++) {
    //         printf("%2d", dp[i][j]);
    //     }
    //     puts("");
    // }

    printf("%d", mx);
}