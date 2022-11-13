#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)

int main()
{
    INP;
    
    int n, tmp, cnt = 0;;
    cin >> n;
    while(n > 0) {
        int r = 0;
        cnt++;
        tmp = cnt;
        while(tmp > 0) {
            r++;
            tmp /= 10;
        }
        n -= r;
    }
    
    int a = abs(n);
    int ans;
    for(int i=0 ; i<=a ; i++) {
        ans = cnt % 10;
        cnt /= 10;
    }
    cout << ans;
}