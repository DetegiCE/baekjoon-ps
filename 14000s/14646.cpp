#include<bits/stdc++.h>
using namespace std;

int stk[100001];
int mx, cur;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    for(int i=0 ; i<n*2 ; i++) {
        int t;
        cin >> t;
        if(stk[t] == 0) {
            stk[t] = 1;
            cur++;
            mx = max(mx, cur);
        }
        else {
            cur--;
        }
    }
    cout << mx;
}
