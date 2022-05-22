#include<cstdio>

int main()
{
    int n, p[1001], flag = 0, cnt1 = 0;
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &p[i]);
        if(p[i] == 1) cnt1++;
    }
    if(cnt1 == n) {
        printf("%s", cnt1%2?"cubelover":"koosaga");
        return 0;
    }
    if(!(cnt1%2) && cnt1) {
        for(int i=0 ; i<n ; i++) {
            if(p[i] > 1) {
                p[i] = 1;
                break;
            }
        }
    }
    int g = 0;
    for(int i=0 ; i<n ; i++) g ^= p[i];
    printf("%s", g?"koosaga":"cubelover");
}