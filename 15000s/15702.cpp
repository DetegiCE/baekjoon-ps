#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

int main()
{
    INP;
    
    int n, m;
    int scores[101];
    
    int mxs = -1, mxi = 999;
    cin >> n >> m;
    for(int i=0 ; i<n ; i++) cin >> scores[i];
    for(int i=0 ; i<m ; i++) {
        int num, sc = 0;
        cin >> num;
        for(int j=0 ; j<n ; j++) {
            char o;
            cin >> o;
            if(o == 'O') sc += scores[j];
        }
        if(sc > mxs) {
            mxs = sc;
            mxi = num;
        }
        else if(sc == mxs) {
            mxi = min(mxi, num);
        }
    }
    cout << mxi << ' ' << mxs;
}