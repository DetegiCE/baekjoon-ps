#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int w, h;
string mp[1002];
int fr[1002][1002];
int sg[1002][1002];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

void f() {
    queue<pii> fq, sq;
    cin >> w >> h;
    for(int i=0 ; i<h ; i++) {
        for(int j=0 ; j<w ; j++) {
            fr[i][j] = sg[i][j] = 99999999;
        }
    }
    for(int i=0 ; i<h ; i++) {
        cin.ignore();
        cin >> mp[i];
        for(int j=0 ; j<w ; j++) {
            if(mp[i][j] == '@') {
                sq.push(pii(i, j));
                sg[i][j] = 0;
            }
            if(mp[i][j] == '*') {
                fq.push(pii(i, j));
                fr[i][j] = 0;
            }
        }
    }
    
    while(!fq.empty()) {
        pii qf = fq.front();
        fq.pop();
        int qfy = qf.first;
        int qfx = qf.second;
        int qfv = fr[qfy][qfx];
        
        for(int i=0 ; i<4 ; i++) {
            int nxy = qfy + dy[i];
            int nxx = qfx + dx[i];
            if(!(0 <= nxy && nxy < h && 0 <= nxx && nxx < w)) continue;
            if(mp[nxy][nxx] == '#') continue;
            if(fr[nxy][nxx] <= fr[qfy][qfx] + 1) continue;
            fr[nxy][nxx] = fr[qfy][qfx] + 1;
            fq.push(pii(nxy, nxx));
        }
    }
    
    while(!sq.empty()) {
        pii qf = sq.front();
        sq.pop();
        int qfy = qf.first;
        int qfx = qf.second;
        int qfv = sg[qfy][qfx];
        
        for(int i=0 ; i<4 ; i++) {
            int nxy = qfy + dy[i];
            int nxx = qfx + dx[i];
            if(!(0 <= nxy && nxy < h && 0 <= nxx && nxx < w)) continue;
            if(mp[nxy][nxx] == '#') continue;
            if(sg[nxy][nxx] <= sg[qfy][qfx] + 1) continue;
            if(sg[qfy][qfx] + 1 >= fr[nxy][nxx]) continue;
            sg[nxy][nxx] = sg[qfy][qfx] + 1;
            sq.push(pii(nxy, nxx));
        }
    }
    
    int mn = 99999999;
    for(int i=0 ; i<h ; i++) {
        mn = min(mn, sg[i][0]);
        mn = min(mn, sg[i][w-1]);
    }
    for(int i=0 ; i<w ; i++) {
        mn = min(mn, sg[0][i]);
        mn = min(mn, sg[h-1][i]);
    }
    
    // for(int i=0 ; i<h ; i++) {
    //     for(int j=0 ; j<w ; j++) {
    //         if(fr[i][j] == 99999999) cout << "X ";
    //         else cout << fr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // for(int i=0 ; i<h ; i++) {
    //     for(int j=0 ; j<w ; j++) {
    //         if(sg[i][j] == 99999999) cout << "X ";
    //         else cout << sg[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "\n==========================\n";
    
    
    if(mn == 99999999) cout << "IMPOSSIBLE\n";
    else cout << mn + 1 << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        f();
    }
}
