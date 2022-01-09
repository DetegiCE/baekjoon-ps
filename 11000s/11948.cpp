#include<cstdio>
#define MIN(A,B) (A>B?B:A)
#define MAX(A,B) (A>B?A:B)
#define SUM(A,B) (A+B)

int main()
{
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    printf("%d", SUM(SUM(SUM(a,b), SUM(c,d))-MIN(MIN(a,b), MIN(c,d)), MAX(e,f)));
}
