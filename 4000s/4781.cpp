#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n, m;
double dm;
vector<pii> v;

void f() {
    int dp[10004];
    for(int i=0 ; i<=m ; i++) dp[i] = 0;
    v.clear();
    for(int i=0 ; i<n ; i++) {
        int a, b;
        double db;
        cin >> a >> db;
        b = (int)(db*100+0.5);
        for(int i=0 ; i<=m-b ; i++) dp[i+b] = max(dp[i+b], dp[i]+a);
    }
    int ans = 0;
    for(int i=0 ; i<=m ; i++) ans = max(ans, dp[i]);
    cout << ans << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while(true) {
        cin >> n >> dm;
        if(n == 0) break;
        m = (int)(dm*100+0.5);
        f();
    }
}
