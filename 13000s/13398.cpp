#include<bits/stdc++.h>
using namespace std;

int n;
int a[100002];
int frnt[100002];
int back[100002];
int mx = -1001;

int main()
{
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++) {
        scanf("%d", &a[i]);
        mx = max(mx, a[i]);
    }
    if(mx < 0) {
        printf("%d", mx);
        return 0;
    }
    for(int i=1 ; i<=n ; i++) {
        frnt[i] = max(frnt[i-1]+a[i], max(a[i], 0));
    }
    for(int i=n ; i>=1 ; i--) {
        back[i] = max(back[i+1]+a[i], max(a[i], 0));
    }
    for(int i=1 ; i<=n ; i++) {
        mx = max(mx, max(frnt[i-1]+back[i+1], frnt[i-1]+a[i]+back[i+1]));
    }
    printf("%d", mx);
}
