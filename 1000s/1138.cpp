#include<bits/stdc++.h>
using namespace std;

int b[12];

int main()
{
    int n;
    int a[12];
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++) {
        scanf("%d", &a[i]);
    }
    for(int i=1 ; i<=n ; i++) {
        int t = 0;
        for(int j=1 ; j<=12 ; j++) {
            if(t == a[i] && b[j] == 0) {
                b[j] = i;
                break;
            }
            if(b[j] == 0) t++;
        }
    }
    for(int i=1 ; i<=n ; i++) printf("%d ", b[i]);
}