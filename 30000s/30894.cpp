#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pip = pair<int,pii>;

int n, m;
int sx, sy, ex, ey;
string mp[4][202];
int ghost[4][202][202];
int vis[202][202];

priority_queue<pip, vector<pip>, greater<pip> > q;

int dy[5] = {0,-1,0,1,0};
int dx[5] = {0,0,1,0,-1};

int main()
{
    cin.tie(0)->sync_with_stdio(0);    
    cin >> n >> m;
    cin >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;
    for(int i=0 ; i<n ; i++) {
        cin.ignore();
        cin >> mp[0][i];
        mp[1][i] = mp[2][i] = mp[3][i] = mp[0][i];
    }
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            if(mp[1][i][j] == '0') mp[1][i][j] = '1';
            else if(mp[1][i][j] == '1') mp[1][i][j] = '2';
            else if(mp[1][i][j] == '2') mp[1][i][j] = '3';
            else if(mp[1][i][j] == '3') mp[1][i][j] = '0';
        }
    }
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            if(mp[2][i][j] == '0') mp[2][i][j] = '2';
            else if(mp[2][i][j] == '1') mp[2][i][j] = '3';
            else if(mp[2][i][j] == '2') mp[2][i][j] = '0';
            else if(mp[2][i][j] == '3') mp[2][i][j] = '1';
        }
    }
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            if(mp[3][i][j] == '0') mp[3][i][j] = '3';
            else if(mp[3][i][j] == '1') mp[3][i][j] = '0';
            else if(mp[3][i][j] == '2') mp[3][i][j] = '1';
            else if(mp[3][i][j] == '3') mp[3][i][j] = '2';
        }
    }
    for(int t=0 ; t<4 ; t++) {
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(mp[t][i][j] == '0') {
                    int cury = i;
                    int curx = j+1;
                    ghost[t][i][j] = 1;
                    while(curx < m && mp[t][i][curx] == '.') {
                        ghost[t][i][curx] = 1;
                        curx++;
                    }
                }
                if(mp[t][i][j] == '1') {
                    int cury = i+1;
                    int curx = j;
                    ghost[t][i][j] = 1;
                    while(cury < n && mp[t][cury][j] == '.') {
                        ghost[t][cury][j] = 1;
                        cury++;
                    }
                }
                if(mp[t][i][j] == '2') {
                    int cury = i;
                    int curx = j-1;
                    ghost[t][i][j] = 1;
                    while(curx >= 0 && mp[t][i][curx] == '.') {
                        ghost[t][i][curx] = 1;
                        curx--;
                    }
                }
                if(mp[t][i][j] == '3') {
                    int cury = i-1;
                    int curx = j;
                    ghost[t][i][j] = 1;
                    while(cury >= 0 && mp[t][cury][j] == '.') {
                        ghost[t][cury][j] = 1;
                        cury--;
                    }
                }
            }
        }
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(ghost[t][i][j])
                    mp[t][i][j] = '#';
            }
        }
    }

    // for(int t=0 ; t<4 ; t++) {
    //     for(int i=0 ; i<n ; i++) {
    //         cout << mp[t][i] << '\n';
    //     }
    //     cout << '\n';
    // }

    vis[sx][sy] = 1;
    q.push(pip(0, pii(sx, sy)));
    while(!q.empty()) {
        pip qf = q.top();
        q.pop();

        int qft = qf.first;
        int qfx = qf.second.first;
        int qfy = qf.second.second;

        // cout << qft << ' ' << qfx << ' ' << qfy << '\n';
        if(qfx == ex && qfy == ey) {
            cout << qft;
            return 0;
        }

        for(int i=0 ; i<5 ; i++) {
            int nxx = qfx + dx[i];
            int nxy = qfy + dy[i];
            if(!(0 <= nxx && nxx < n && 0 <= nxy && nxy < m)) continue;
            // for(int j=1 ; j<=4 ; j++) {
            //     if(mp[(qft+j)%4][nxx][nxy] == '.' && (vis[nxx][nxy] & (1<<((qft+j)%4))) == 0) {
            //         q.push(pip(qft+j, pii(nxx, nxy)));
            //         vis[nxx][nxy] |= (1<<((qft+j)%4));
            //         break;
            //     }
            // }
            if(mp[(qft+1)%4][nxx][nxy] == '.' && (vis[nxx][nxy] & (1<<((qft+1)%4))) == 0) {
                q.push(pip(qft+1, pii(nxx, nxy)));
                vis[nxx][nxy] |= (1<<((qft+1)%4));
            }
        }
    }
    cout << "GG";
}
