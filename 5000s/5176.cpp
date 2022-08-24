#include<bits/stdc++.h>
using namespace std;

void sol() {
    int p, m;
    int seat[501] = {0};
    scanf("%d %d", &p, &m);
    int cnt = 0;
    for(int i=0 ; i<p ; i++) {
        int a;
        scanf("%d", &a);
        if(seat[a] != 0) cnt++;
        else seat[a] = 1;
    }
    printf("%d\n", cnt);
}

int main()
{
    int k;
    scanf("%d", &k);
    for(int i=0 ; i<k ; i++) {
        sol();
    }
}