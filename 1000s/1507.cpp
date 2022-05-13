#include<cstdio>

int n;
int orig[22][22], mapp[22][22];

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            scanf("%d", &mapp[i][j]);
            orig[i][j] = mapp[i][j];
        }
    }
    for(int i=0 ; i<n ; i++) {
        for(int j=i+1 ; j<n ; j++) {
            for(int k=0 ; k<n ; k++) {
                if(i == k || j == k) continue;
                if(mapp[i][j] == mapp[i][k] + mapp[k][j]) {
                    orig[i][j] = 0;
                }
                else if(mapp[i][j] > mapp[i][k] + mapp[k][j]) {
                    printf("-1");
                    return 0;
                }
            }
        }
    }
    int sum = 0;
    for(int i=0 ; i<n ; i++) {
        for(int j=i+1 ; j<n ; j++) {
            sum += orig[i][j];
        }
    }
    printf("%d", sum);
}