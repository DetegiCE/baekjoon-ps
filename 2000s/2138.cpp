#include<bits/stdc++.h>
using namespace std;

int n, ans = -1;
int a[100001];
int b[100001];

void flip(int pos) {
    a[pos] = 1 - a[pos];
}

void f(int pos, int cnt) {
    if(pos == 0) {
        f(1, 0);
        
        flip(0);
        flip(1);
        f(1, 1);
        flip(0);
        flip(1);
    }
    else if(pos == n-1) {
        if(a[pos-1] == b[pos-1] && a[pos] == b[pos]) {
            f(pos+1, cnt);
        }
        else if(a[pos-1] != b[pos-1] && a[pos] != b[pos]) {
            flip(pos-1);
            flip(pos);
            f(pos+1, cnt+1);
            flip(pos-1);
            flip(pos);
        }
    }
    else if(pos == n) {
        if(ans == -1) ans = cnt;
        else ans = min(ans, cnt);
    }
    else {
        if(a[pos-1] == b[pos-1]) f(pos+1, cnt);
        else {
            flip(pos-1);
            flip(pos);
            flip(pos+1);
            f(pos+1, cnt+1);
            flip(pos-1);
            flip(pos);
            flip(pos+1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) scanf("%1d", &a[i]);
    for(int i=0 ; i<n ; i++) scanf("%1d", &b[i]);
    f(0, 0);
    printf("%d", ans);
}