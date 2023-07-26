#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int a[12][12];
int nut[12][12];
vector<int> age[12][12];
queue<int> liv[12][12];
queue<int> ded[12][12];

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m >> k;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            cin >> a[i][j];
            nut[i][j] = 5;
        }
    }
    for(int i=0 ; i<m ; i++) {
        int r, c, g;
        cin >> r >> c >> g;
        age[r][c].push_back(g);
    }
    while(k--) {
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n ; j++) {
                if(age[i][j].size() > 0) {
                    sort(age[i][j].begin(), age[i][j].end());
                    for(auto t: age[i][j]) {
                        if(t <= nut[i][j]) {
                            liv[i][j].push(t+1);
                            nut[i][j] -= t;
                        }
                        else {
                            ded[i][j].push(t);
                        }
                    }
                    age[i][j].clear();
                    while(!liv[i][j].empty()) {
                        age[i][j].push_back(liv[i][j].front());
                        liv[i][j].pop();
                    }
                }
            }
        }
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n ; j++) {
                while(!ded[i][j].empty()) {
                    nut[i][j] += (ded[i][j].front()) / 2;
                    ded[i][j].pop();
                }
            }
        }
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n ; j++) {
                for(auto t: age[i][j]) {
                    if(t % 5 == 0) {
                        for(int p=0 ; p<8 ; p++) {
                            int ny = i+dy[p];
                            int nx = j+dx[p];
                            if(!(1 <= ny && ny <= n && 1 <= nx && nx <= n)) continue;
                            age[ny][nx].push_back(1);
                        }
                    }
                }
            }
        }
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n ; j++) {
                nut[i][j] += a[i][j];
            }
        }
    }
    
    int cnt = 0;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            cnt += age[i][j].size();
        }
    }
    
    cout << cnt;
}
