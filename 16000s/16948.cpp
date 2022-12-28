#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define MP(A,B) make_pair(A,B)

int n, r1, c1, r2, c2;
int mapp[203][203];
queue<pii> q;
int dy[6] = {-2,-2,0,0,2,2};
int dx[6] = {-1,1,-2,2,-1,1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            mapp[i][j] = -1;
        }
    }
    mapp[r1][c1] = 0;
    q.push(MP(r1,c1));
    while(!q.empty()) {
        pii qf = q.front();
        q.pop();
        int qfy = qf.first;
        int qfx = qf.second;
        
        for(int i=0 ; i<6 ; i++) {
            int nfy = qfy + dy[i];
            int nfx = qfx + dx[i];
            if(0 <= nfy && nfy < n && 0 <= nfx && nfx < n && mapp[nfy][nfx] == -1) {
                if(nfy == r2 && nfx == c2) {
                    cout << mapp[qfy][qfx] + 1;
                    return 0;
                }
                mapp[nfy][nfx] = mapp[qfy][qfx] + 1;
                q.push(MP(nfy, nfx));
            }
        }
    }
    
    cout << -1;
}