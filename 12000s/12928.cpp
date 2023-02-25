#include<bits/stdc++.h>
using namespace std;
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)

typedef pair<int,int> pii;

int n, s;
set<int> dp[51];

/*
sum of 0, 1, 3, 6, 10, ... be S
sum of 1, 2, 3, 4, 5, ... be 2(N-1)
*/

/*
3 -> 4
 -1+2+1 (-0+1+0)
 -2+3+1 (-1+3+0)
 
4 -> 5
 -1+2+1
 -2+3+1
 -3+4+1
*/

int conv(int nodes) {
    return (nodes+1)*nodes/2;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> s;
    dp[2].insert(0);
    for(int i=2; i<=n ; i++) {
        for(auto k: dp[i]) {
            for(int j=1 ; j<=n-i ; j++) {
                dp[i+j].insert(k+conv(j));
            }
        }
    }
    // for(int i=2 ; i<=n ; i++) {
    //     for(auto k: dp[i]) {
    //         cout << k << ' ';
    //     }
    //     cout << '\n';
    // }
    if(dp[n].find(s) != dp[n].end()) cout << 1;
    else cout << 0;
}
