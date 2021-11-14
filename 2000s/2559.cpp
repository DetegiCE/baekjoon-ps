#include<cstdio>

int a[100001];
int s[100001];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1 ; i<=n ; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];
    }
    int mx = 0x80000000;
    for(int i=k ; i<=n ; i++) {
        mx = mx > s[i]-s[i-k] ? mx : s[i]-s[i-k];
    }
    printf("%d", mx);
}
