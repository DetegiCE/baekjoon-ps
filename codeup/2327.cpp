#include<cstdio>

int n;
int c[3001], d[3001];
int a, b, cnt;

int main()
{
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++) {
        scanf("%d", &c[i]);
        if(i-1) d[i] = d[i-1] + c[i];
        else d[i] = c[i];
    }
    scanf("%d %d", &a, &b);
    int sum = d[b] - d[a-1];
    for(int i=1 ; i<=n ; i++) {
        for(int j=i ; j<=n ; j++) {
            int tmp = d[j] - d[i-1];
            if(tmp == sum) cnt++;
        }
    }
    printf("%d", cnt);
}