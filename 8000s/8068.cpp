#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define MP(A,B) make_pair(A,B)
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

int n, m, ans;
int a[102][102];
bool vis[102][102];
priority_queue<pip, vector<pip>, greater<pip> > pq;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

bool inborder(int y, int x) {
    return (0 <= y && y < n && 0 <= x && x < m);
}

int main()
{
    INP;
    
    cin >> n >> m;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            cin >> a[i][j];
            if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                pq.push(MP(a[i][j], MP(i, j)));
            }
        }
    }
    while(!pq.empty()) {
        pip pt = pq.top();
        while(!pq.empty()) {
            pip pt2 = pq.top();
            if(pt2.first > pt.first) break;
            pq.pop();
            
            if(vis[pt2.second.first][pt2.second.second]) continue;
            vis[pt2.second.first][pt2.second.second] = true;
            
            ans += pt.first - pt2.first;
            for(int i=0 ; i<4 ; i++) {
                int ny = pt2.second.first + dy[i];
                int nx = pt2.second.second + dx[i];
                if(inborder(ny, nx)) {
                    pq.push(MP(a[ny][nx], MP(ny, nx)));
                }
            }
        }
    }
    cout << ans;
}