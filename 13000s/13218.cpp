#include<cstdio>

#define MIN(A,B) (A>B?B:A)
#define MAX(A,B) (A>B?A:B)
#define SQ(A) ((A)*(A))

int pos[3001][2];

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=0 ; i<n ; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x += 1500, y += 1501;
        if(pos[x][0]) {
            pos[x][0] = MIN(pos[x][0], y);
            pos[x][1] = MAX(pos[x][1], y);
        }
        else {
            pos[x][0] = y;
            pos[x][1] = y;
        }
    }

    int ans = 0;
    for(int i=0 ; i<3000 ; i++) {
        if(pos[i][0]) { 
            ans = MAX(ans, SQ(pos[i][1] - pos[i][0]));
            for(int j=i+1 ; j<3000 ; j++) {
                if(pos[j][0]) {
                    ans = MAX(ans, SQ(j-i) + MAX(SQ(pos[i][1]-pos[j][0]), SQ(pos[i][0]-pos[j][1])));
                }
            }
        }
    }
    printf("%d", ans);
}