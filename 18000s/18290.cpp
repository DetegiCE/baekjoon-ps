#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int mapp[101];
bool vis[101];

int mx = -100000000;
int sum = 0;

void f(int pos, int sel) {
    if(sel == k) {
        mx = max(mx, sum);
        return;
    }
    if(pos == n*m) return;
    if((pos-1 >= 0 && !vis[pos-1] || pos%m == 0) && (pos+1 < n*m && !vis[pos+1] || pos%m == (m-1)) && (pos-m >= 0 && !vis[pos-m] || pos/m==0) && (pos+m < n*m && !vis[pos+m] || pos/m==n-1)) {
        vis[pos] = true;
        sum += mapp[pos];
        f(pos+1, sel+1);
        sum -= mapp[pos];
        vis[pos] = false;
        f(pos+1, sel);
    }
    else f(pos+1, sel);
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            scanf("%d", &mapp[i*m+j]);
        }
    }
    f(0,0);
    printf("%d", mx);
}