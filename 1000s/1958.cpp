#include<cstdio>
#include<cstring>

#define MAX2(A,B) ((A)>(B)?(A):(B))
#define MAX3(A,B,C) (MAX2(A,B)>C?MAX2(A,B):C)

char a[102], b[102], c[102];
int dp[102][102][102], alen, blen, clen;

int main()
{
    scanf("%s", &a[1]);
    scanf("%s", &b[1]);
    scanf("%s", &c[1]);
    alen = strlen(&a[1]);
    blen = strlen(&b[1]);
    clen = strlen(&c[1]);

    for(int i=1 ; i<=alen ; i++) {
        for(int j=1 ; j<=blen ; j++) {
            for(int k=1 ; k<=clen ; k++) {
                if(a[i] == b[j] && b[j] == c[k]) 
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else 
                    dp[i][j][k] = MAX3(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]);
            }
        }
    }
    printf("%d", dp[alen][blen][clen]);
}