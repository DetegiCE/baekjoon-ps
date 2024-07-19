#include<bits/stdc++.h>
using namespace std;

vector<int> ord[4][11];
int pos[103][103];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    for(int i=0 ; i<4 ; i++) ord[i][0].push_back(i);
    for(int i=0 ; i<4 ; i++) {
        for(int j=1 ; j<=10 ; j++) {
            for(int k=0 ; k<ord[i][j-1].size() ; k++) {
                ord[i][j].push_back(ord[i][j-1][k]);
            }
            for(int k=ord[i][j-1].size()-1 ; k>=0 ; k--) {
                ord[i][j].push_back((ord[i][j-1][k]+1)%4);
            }
        }
    }

    int n;
    cin >> n;
    while(n--) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        for(int p: ord[d][g]) {
            if(x >= 0 && y >= 0 && x <= 100 && y <= 100)
                pos[x][y] = 1;
            x += dx[p];
            y += dy[p];
        }
        if(x >= 0 && y >= 0 && x <= 100 && y <= 100)
            pos[x][y] = 1;
    }

    int cnt = 0;
    for(int i=0 ; i<100 ; i++) {
        for(int j=0 ; j<100 ; j++) {
            if(pos[i][j] && pos[i][j+1] && pos[i+1][j] && pos[i+1][j+1]) cnt++;
        }
    }
    cout << cnt;
}