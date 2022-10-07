#include<bits/stdc++.h>
using namespace std;

string dp[51][11]; //dp[i][j] = i원 채웠을 때 마지막으로 쓴 숫자가 j
int p[11];
int n, m;

int compare_str(string a, string b) {
    int alen = a.length();
    int blen = b.length();
    if(alen == blen) {
        if(a < b) return 1;
        else if(a == b) return 0;
        else return -1;
    }
    else {
        if(alen < blen) return 1;
        else return -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        cin >> p[i];
    }
    cin >> m;
    for(int i=0 ; i<=m ; i++) {
        for(int j=0 ; j<n ; j++) {
            dp[i][j] = "";
        }
    }
    
    int mn = 51;
    for(int i=0 ; i<n ; i++) {
        dp[p[i]][i] = to_string(i);
        mn = min(mn, p[i]);
    }
    
    for(int i=mn ; i<=m ; i++) {
        for(int j=0 ; j<n ; j++) {
            if(i < p[j]) continue;
            for(int k=0 ; k<n ; k++) {
                if(dp[i-p[j]][k] == "") continue;
                int res = compare_str(dp[i][j], to_string(j) + dp[i-p[j]][k]);
                if(res == 1) dp[i][j] = to_string(j) + dp[i-p[j]][k];
            }
        }   
    }
    
    // for(int i=0 ; i<=m ; i++) {
    //     for(int j=0 ; j<n ; j++) {
    //         if(dp[i][j] == "") cout << "[] ";
    //         else cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    string ans = "";
    for(int i=0 ; i<=m ; i++) {
        for(int j=0 ; j<n ; j++) {
            if(dp[i][j].length() > 1 && dp[i][j][0] == '0') continue;
            int res = compare_str(ans, dp[i][j]);
            if(res == 1) ans = dp[i][j];
        }
    }
    cout << ans;
}
