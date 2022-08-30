#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ocnt;
vector<ll> opos;

int main()
{
    int n;
    scanf("%d", &n);
    if(n <= 2) {
        puts("0");
        return 0;
    }
    for(int i=0 ; i<n ; i++) {
        int t;
        scanf("%d", &t);
        if(t%2) {
            ocnt++;
            opos.push_back(i);
        }
    }
    // 00011
    
    ll left = 0;
    for(int i=0 ; i<ocnt ; i++) {
        left += opos[i] - i;
    }
    
    ll right = 0;
    for(int i=ocnt-1 ; i>=0 ; i--) {
        right += n-(ocnt-1-i)-1 - opos[i];
    }
    
    printf("%lld", min(left, right));
}