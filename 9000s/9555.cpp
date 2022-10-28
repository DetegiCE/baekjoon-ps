#include<bits/stdc++.h>
using namespace std;

int n, m;
int mapp[103][103];
int cnt = 0;

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

void color(int c) {
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            if(mapp[i][j] == c) mapp[i][j] = -1;
        }
    }
}

void sol() {
    cnt = 0;
    
    cin >> n >> m;
    for(int i=0 ; i<=n+1 ; i++) {
        for(int j=0 ; j<=m+1 ; j++) {
            mapp[i][j] = -1;
        }
    }
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            cin >> mapp[i][j];
        }
    }
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            if(mapp[i][j] != -1) {
                for(int k=0 ; k<8 ; k++) {
                    if(mapp[i][j] == mapp[i+dx[k]][j+dy[k]]) {
                        cnt++;
                        color(mapp[i][j]);
                        break;
                    }
                }
            }
        }
    }
    cout << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
}