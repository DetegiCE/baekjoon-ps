#include<cstdio>
#define UP (paper[i-1][j])
#define DOWN (paper[i+1][j])
#define LEFT (paper[i][j-1])
#define RIGHT (paper[i][j+1])
#define MIN(A,B) (A>B?B:A)

int paper[104][104], cnt;

int main()
{
    int n;
    scanf("%d", &n);
    while(n--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        for(int i=a ; i<MIN(100,a+c) ; i++) {
            for(int j=b ; j<MIN(100,b+c) ; j++) {
                paper[i][j] = 1;
            }
        }
    }

    for(int i=1 ; i<=99 ; i++) {
        for(int j=1 ; j<=99 ; j++) {
            if(paper[i][j] == 1) {
                //printf("(%d %d) -> U%d D%d L%d R%d\n", i, j, UP, DOWN, LEFT, RIGHT);
                cnt += !UP;
                cnt += !DOWN;
                cnt += !LEFT;
                cnt += !RIGHT;
            }
        }
    }
    printf("%d", cnt);
}