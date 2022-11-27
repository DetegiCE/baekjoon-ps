#include<bits/stdc++.h>
using namespace std;
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef pair<int,int> pii;

int r, c;
int board[103][103];
int chs;
vector<int> ans;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool inborder(int y, int x) {
    return 0 <= y && y < r && 0 <= x && x < c;
}

void melt() {
    queue<pii> q;
    q.push(MP(0,0));
    while(!q.empty()) {
        pii qf = q.front();
        q.pop();
        int fy = qf.first;
        int fx = qf.second;
        
        for(int i=0 ; i<4 ; i++) {
            int ny = fy + dy[i];
            int nx = fx + dx[i];
            if(inborder(ny, nx) && board[ny][nx] == 0) {
                board[ny][nx] = 2;
                q.push(MP(ny, nx));
            }
        }
    }
    
    for(int i=0 ; i<r ; i++) {
        for(int j=0 ; j<c ; j++) {
            if(board[i][j] == 1) {
                for(int k=0 ; k<4 ; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(inborder(ny, nx) && board[ny][nx] == 2) {
                        board[i][j] = 3;
                        break;
                    }
                }
            }
        }
    }
    for(int i=0 ; i<r ; i++) {
        for(int j=0 ; j<c ; j++) {
            if(board[i][j] == 2) board[i][j] = 0;
            else if(board[i][j] == 3) {
                chs--;
                board[i][j] = 0;
            }
        }
    }
    if(chs > 0) ans.PB(chs);
}

int main()
{
    scanf("%d %d", &r, &c);
    for(int i=0 ; i<r ; i++) {
        for(int j=0 ; j<c ; j++) {
            scanf("%d", &board[i][j]);
            chs += board[i][j];
        }
    }
    ans.PB(chs);
    while(chs > 0) {
        melt();
    }
    printf("%d\n%d", ans.size(), ans[ans.size()-1]);
}