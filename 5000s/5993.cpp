#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define MP(A,B) make_pair(A,B)

int x, y, mx, my, mxv;
string mapp[102];
int tim[102][102];
queue<pii> q;

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

inline bool inborder(int yy, int xx) {
    return 0 <= yy && yy < y && 0 <= xx && xx < x;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> x >> y >> mx >> my;
    mx--;
    my = y - my;
    for(int i=0 ; i<y ; i++) {
        cin >> mapp[i];
        for(int j=0 ; j<x ; j++) {
            tim[i][j] = 1e9;
        }
    }
    
    tim[my][mx] = 0;
    q.push(MP(my,mx));
    while(!q.empty()) {
        pii qf = q.front();
        q.pop();
        int qfy = qf.first;
        int qfx = qf.second;
        mxv = max(mxv, tim[qfy][qfx]);
        
        for(int i=0 ; i<8 ; i++) {
            int nxy = qfy + dy[i];
            int nxx = qfx + dx[i];
            if(inborder(nxy, nxx) && mapp[nxy][nxx] == '.' && tim[nxy][nxx] > tim[qfy][qfx] + 1) {
                q.push(MP(nxy, nxx));
                tim[nxy][nxx] = tim[qfy][qfx] + 1;
            }
        }
    }
    cout << mxv;
}
