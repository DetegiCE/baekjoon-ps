#include<bits/stdc++.h>
using namespace std;

int n, m;
string mapp[602];
int sy, sx;
int cnt;

void f(int y, int x) {
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    if(mapp[y][x] == 'P') cnt++;
    mapp[y][x] = 'X';
    for(int i=0 ; i<4 ; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(0 <= ny && ny < n && 0 <= nx && nx < m && mapp[ny][nx] != 'X') {
            f(ny, nx);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    cin.ignore();
    for(int i=0 ; i<n ; i++) {
        cin >> mapp[i];
        for(int j=0 ; j<m ; j++) {
            if(mapp[i][j] == 'I') {
                sy = i;
                sx = j;
            }
        }
    }
    f(sy, sx);
    if(cnt == 0) cout << "TT";
    else cout << cnt;
}
