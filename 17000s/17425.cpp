#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll acc[1000002];

void makeP1000() {
    for(int i=1 ; i<=1000000 ; i++) {
        for(int j=i ; j<=1000000 ; j+=i) {
            acc[j] += i;
        }
        acc[i] += acc[i-1];
    }
}

int main()
{
    int t;
    makeP1000();
    scanf("%d", &t);
    for(int i=0 ; i<t ; i++) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", acc[n]);
    }
}