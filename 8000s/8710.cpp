#include<cstdio>

int main()
{
    int k, w, m;
    scanf("%d %d %d", &k, &w, &m);
    printf("%d", w>k?(w-k-1)/m+1:0);
}
