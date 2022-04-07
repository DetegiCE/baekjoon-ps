#include <cstdio>
#define MIN(A, B) (A > B ? B : A)
#define MAX(A, B) (A > B ? A : B)

int main()
{
    int n, a0, a[101], t;
    scanf("%d", &n);
    scanf("%d", &a0);
    int ans = 0;
    int cur = a0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        int sm = MIN(t, cur);
        int lg = MAX(t, cur);
        ans += MIN(lg - sm, sm - lg + 360);
        cur = t;
    }
    printf("%d", ans);
}
