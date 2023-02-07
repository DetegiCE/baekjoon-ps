#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, t;
int bp[10001], dp[10001], mx;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> t;
    for(int i=1 ; i<=t ; bp[i] = -1, i++);
    for(int i=0 ; i<n ; i++) {
        int k, s;
        cin >> k >> s;
        for(int j=0 ; j<k ; j++) dp[j] = bp[j];
        for(int j=k ; j<=t ; j++) {
            if(bp[j-k] != -1 && bp[j-k] + s > dp[j]) {
                dp[j] = bp[j-k] + s;
            }
        }
        for(int j=0 ; j<=t ; bp[j] = dp[j], mx = max(mx, bp[j]), j++);
    }
    cout << mx;
}
