#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 987654321
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;

int len, dp[2505];
string s;

bool ispal(int st, int en) {
    for(int i=st ; i<=en ; i++) {
        if(s[i] != s[en-i+st]) return false;
        if(i > en-i+st) return true;
    }
    return true;
}

int f(int pos) {
    // cout << "f( " << pos << ")\n";
    if(dp[pos] != 0) return dp[pos];
    if(pos >= len) return dp[pos] = 0;
    
    dp[pos] = 999999;
    for(int i=pos ; i<len ; i++) {
        if(ispal(pos, i)) {
            dp[pos] = min(dp[pos], f(i+1)+1);
        }
    }
    return dp[pos];
}

int main()
{
    INP;
    
    cin >> s;
    len = s.length();
    cout << f(0);
}