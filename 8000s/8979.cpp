#include<stdio.h>
int medal[1007][4];
int main(void)
{
    int n, k;
    int a, i;
    int rank = 1;
    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a);
        scanf("%d %d %d", &medal[a][1], &medal[a][2], &medal[a][3]);
    }
    for(i = 1; i <= n; i++)
    {
        if(medal[i][1] > medal[k][1]
                || medal[i][1] == medal[k][1] && medal[i][2] > medal[k][2]
                || medal[i][1] == medal[k][1] && medal[i][2] == medal[k][2] && medal[i][3] >
                medal[k][3])
            rank++;
    }
    printf("%d\n", rank);
    return 0;
}

