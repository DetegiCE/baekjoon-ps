#include<bits/stdc++.h>
using namespace std;

int ar[2000003];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        int t;
        scanf("%d", &t);
        ar[t+1000000] = 1;
    }
    for(int i=2000001 ; i>=0 ; i--) {
        if(ar[i]) printf("%d\n", i-1000000);
    }
}