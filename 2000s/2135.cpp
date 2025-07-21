#include <bits/stdc++.h>
using namespace std;

string s;
int dp[201][201];
int len;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    len = s.size();
    for(int i=0 ; i<len ; i++) {
        dp[i][i+1] = 1;
    }

    for(int sz=2 ; sz<=len ; sz++) {
        vector<int> v;
        for(int i=1 ; i<=sz/2 ; i++) {
            if(sz % i == 0) v.push_back(i);
        }
        for(int i=0 ; i<=len-sz ; i++) {
            int cur = sz;
            for(int j: v) {
                bool flg = true;
                for(int k=i ; k<i+sz ; k+=j) {
                    if(s.substr(i,j) != s.substr(k,j)) {
                        flg = false;
                        break;
                    }
                }
                if(flg) {
                    cur = min(cur, dp[i][i+j]+2+static_cast<int>(to_string(sz/j).size()));
                }
            }
            for(int j=i+1 ; j<i+sz ; j++) {
                cur = min(cur, dp[i][j] + dp[j][i+sz]);
            }
            dp[i][i+sz] = cur;
        }
    }
    cout << dp[0][len];
}