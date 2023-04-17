#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    char s[2001];
    cin >> n >> s;
    for(int len=1 ; len<=n ; len++) {
        int eStart = n-len;
        int sameCount = 0;
        for(int i=0 ; i<len ; i++) {
            if(s[i] == s[eStart + i]) sameCount++;
        }
        if(sameCount == len - 1) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
