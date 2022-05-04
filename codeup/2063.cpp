#include<cstdio>

int n;
int mapp[15][15];
int fuel;
int acc[15][15];

#define MIN(A,B) ((A)<(B)?(A):(B))

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            scanf("%d", &mapp[i][j]);
        }
    }
    mapp[0][n-1] = mapp[n-1][0] = 0;
    scanf("%d", &fuel);
    for(int i=1 ; i<n ; i++) {
        acc[n-1][i] = acc[n-1][i-1] + mapp[n-1][i];
    }
    for(int i=n-2 ; i>=0 ; i--) {
        acc[i][0] = acc[i+1][0] + mapp[i][0];
    }
    for(int i=n-2 ; i>=0 ; i--) {
        for(int j=1 ; j<n ; j++) {
            acc[i][j] = MIN(acc[i+1][j], acc[i][j-1]) + mapp[i][j];
        }
    }
    if(fuel - acc[0][n-1] < 0) {
        printf("NOOOO");
    }
    else {
        printf("%d", fuel - acc[0][n-1]);
    }
}