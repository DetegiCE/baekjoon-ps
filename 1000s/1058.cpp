#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int mapp[51][51];
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        char s[51];
        scanf(" %s", s);
        for(int j=0 ; j<n ; j++) {
            mapp[i][j] = (s[j]=='N'?0:1);
        }
    }
    
    int mxv = 0;
    for(int i=0 ; i<n ; i++) {
        int curv = 0;
        for(int j=0 ; j<n ; j++) {
            if(i == j) continue;
            if(mapp[i][j]) {
                curv++;
                continue;
            }
            for(int k=0 ; k<n ; k++) {
                if(i == k || j == k) continue;
                if(mapp[i][k] && mapp[j][k]) {
                    curv++;
                    break;
                }
            }
        }
        mxv = max(mxv, curv);
    }
    printf("%d", mxv);
}