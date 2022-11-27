#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 987654321
#define MOD 1000000007
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;

int n, m;
queue<pii> q;
int mapp[505][505];
int dst[505][505];
string smap[505];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

bool inborder(int y, int x) {
    return 1 <= y && y <= n && 1 <= x && x <= m;
}

int main()
{
    INP;
    
    cin >> n >> m;
    getline(cin, smap[0]);
    for(int i=1 ; i<=n ; i++) {
        cin >> smap[i];   
    }
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            mapp[i][j] = (smap[i][j-1])-'0';
            dst[i][j] = INF;
        }
    }
    
    q.push(MP(1, 1));
    dst[1][1] = 0;
    while(!q.empty()) {
        pii qf = q.front();
        q.pop();
        int qy = qf.first;
        int qx = qf.second;
        
        for(int i=0 ; i<4 ; i++) {
            int ny = qy + dy[i] * mapp[qy][qx];
            int nx = qx + dx[i] * mapp[qy][qx];
            if(inborder(ny, nx) && dst[ny][nx] > dst[qy][qx] + 1) {
                dst[ny][nx] = dst[qy][qx] + 1;
                q.push(MP(ny, nx));
            }
        }
    }
    if(dst[n][m] == INF) cout << "IMPOSSIBLE";
    else cout << dst[n][m];
}