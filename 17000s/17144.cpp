#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 987654321
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;

int r, c, t;
int mapp[53][53];
int hmap[53][53];
int cur, cdr;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

bool inborder(int y, int x) {
    return 1 <= y && y <= r && 1 <= x && x <= c;
}

bool iscond(int y, int x) {
    return (y == cur && x == 1) || (y == cdr && x == 1);
}

void hwaksan() {
    for(int i=1 ; i<=r ; i++) {
        for(int j=1 ; j<=c ; j++) {
            hmap[i][j] = 0;
        }
    }
    for(int i=1 ; i<=r ; i++) {
        for(int j=1 ; j<=c ; j++) {
            int hcnt = 0;
            for(int k=0 ; k<4 ; k++) {
                int nr = i+dy[k];
                int nc = j+dx[k];
                if(inborder(nr, nc) && !iscond(nr, nc)) {
                    hcnt++;
                    hmap[nr][nc] += mapp[i][j]/5;
                }
            }
            hmap[i][j] -= (mapp[i][j]/5)*hcnt;
        }
    }
    for(int i=1 ; i<=r ; i++) {
        for(int j=1 ; j<=c ; j++) {
            mapp[i][j] += hmap[i][j];
        }
    }
}

void aircond() {
    for(int i=cur-2 ; i>=1 ; i--) mapp[i+1][1] = mapp[i][1];
    for(int i=1 ; i<=c-1 ; i++) mapp[1][i] = mapp[1][i+1];
    for(int i=1 ; i<=cur-1 ; i++) mapp[i][c] = mapp[i+1][c];
    for(int i=c ; i>=3 ; i--) mapp[cur][i] = mapp[cur][i-1];
    mapp[cur][2] = 0;
    for(int i=cdr+1 ; i<=r ; i++) mapp[i][1] = mapp[i+1][1];
    for(int i=1 ; i<=c-1 ; i++) mapp[r][i] = mapp[r][i+1];
    for(int i=r ; i>=cdr+1 ; i--) mapp[i][c] = mapp[i-1][c];
    for(int i=c ; i>=3 ; i--) mapp[cdr][i] = mapp[cdr][i-1];
    mapp[cdr][2] = 0;
}

void printmap() {
    for(int i=1 ; i<=r ; i++) {
        for(int j=1 ; j<=c ; j++) {
            cout << mapp[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    INP;
    cin >> r >> c >> t;
    for(int i=1 ; i<=r ; i++) {
        for(int j=1 ; j<=c ; j++) {
            cin >> mapp[i][j];
            if(mapp[i][j] == -1) {
                if(cur == 0) {
                    cur = i;
                }
                else {
                    cdr = i;
                }
            }
        }
    }
    for(int m=1 ; m<=t ; m++) {
        hwaksan();
        aircond();
    }
    int tcnt = 0;
    for(int i=1 ; i<=r ; i++) {
        for(int j=1 ; j<=c ; j++) {
            if(j == 1 && (i == cur || i == cdr)) continue;
            tcnt += mapp[i][j];
        }
    }
    cout << tcnt;
}