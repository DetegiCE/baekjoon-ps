#include<cstdio>
#include<cmath>

int main()
{
    int y1, m1, d1, y2, m2, d2;
    scanf("%d %d %d", &y1, &m1, &d1);
    scanf("%d %d %d", &y2, &m2, &d2);
    if(y1==y2) printf("0\n");
    else {
        if(m1 > m2) printf("%d\n", y2-y1-1);
        else if(m1 < m2) printf("%d\n", y2-y1);
        else {
            if(d1 > d2) printf("%d\n", y2-y1-1);
            else printf("%d\n", y2-y1);
        }
    }
    printf("%d\n", y2-y1+1);
    printf("%d", y2-y1);
}
