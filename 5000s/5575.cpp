#include<cstdio>

int main()
{
    for(int i=0 ; i<3 ; i++) {
        int h1,m1,s1,h2,m2,s2;
        scanf("%d %d %d %d %d %d", &h1, &m1, &s1, &h2, &m2, &s2);
        int t1 = h1*3600 + m1*60 + s1;
        int t2 = h2*3600 + m2*60 + s2;
        int d = t2 - t1;
        printf("%d %d %d\n", d/3600, d/60%60, d%60);
    }
}
