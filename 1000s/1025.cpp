#include<bits/stdc++.h>
using namespace std;
#define PB(A) push_back(A)
#define ALL(A) (A).begin(), (A).end()

int n, m, mx, cnt;
char mapp[11][11];

bool issq(int n) {
    return sqrt(n)==int(sqrt(n));
}

void start(int y, int x) {
    for(int ydif=-9 ; ydif<=9 ; ydif++) {
        for(int xdif=-9 ; xdif<=9 ; xdif++) {
            if(ydif == 0 && xdif == 0) continue;
            string s = "";
            for(int i=0 ; i<9 ; i++) {
                int ny = y + ydif * i;
                int nx = x + xdif * i;
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) break;
                s += mapp[ny][nx];
                int si = stoi(s);
                if(issq(si)) {
                    mx = max(mx, si);
                    cnt++;
                }
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i=0 ; i<n ; i++) {
        cin >> mapp[i];
    }
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            start(i, j);
        }
    }
    if(cnt) cout << mx;
    else cout << -1;
}
