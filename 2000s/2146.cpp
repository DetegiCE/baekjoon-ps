// 2146
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
#define ALL(A) A.begin(), A.end()
#define ABS(A) ((A)>0?(A):-(A))

int n, islcnt;
int mapp[103][103];
vector<pii> isl[5001];

int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};

inline bool inborder(int y, int x) {
  return 1 <= y && y <= n && 1 <= x && x <= n;
}

inline bool iscoast(int y, int x) {
  for(int i=0 ; i<4 ; i++) {
    if(inborder(y+dy[i], x+dx[i]) && mapp[y+dy[i]][x+dx[i]] == 0) return true;
  }
  return false;
}

int dist(int ax, int ay, int bx, int by) {
  return ABS(ax-bx) + ABS(ay-by);
}

void bfs(int y, int x) {
  queue<pii> q;
  q.push(MP(y, x));
  mapp[y][x] = islcnt;
  while(!q.empty()) {
    pii qf = q.front();
    q.pop();
    int qfy = qf.first;
    int qfx = qf.second;

    for(int i=0 ; i<4 ; i++) {
      int nxy = qfy + dy[i];
      int nxx = qfx + dx[i];
      if(inborder(nxy, nxx) && mapp[nxy][nxx] == -1) {
        mapp[nxy][nxx] = islcnt;
        q.push(MP(nxy, nxx));
      }
    }
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  for(int i=1 ; i<=n ; i++) {
    for(int j=1 ; j<=n ; j++) {
      cin >> mapp[i][j];
      if(mapp[i][j] == 1) mapp[i][j] = -1;
    }
  }

  for(int i=1 ; i<=n ; i++) {
    for(int j=1 ; j<=n ; j++) {
      if(mapp[i][j] == -1) {
        islcnt++;
        bfs(i, j);
      }
    }
  }

  for(int i=1 ; i<=n ; i++) {
    for(int j=1 ; j<=n ; j++) {
      if(mapp[i][j] > 0 && iscoast(i, j)) {
        isl[mapp[i][j]].PB(MP(i, j));
      }
    }
  }

  int mnv = 500;
  for(int i=1 ; i<=islcnt ; i++) {
    for(int j=i+1 ; j<=islcnt ; j++) {
      for(int k=0 ; k<isl[i].size() ; k++) {
        for(int l=0 ; l<isl[j].size() ; l++) {
          int dst = dist(isl[i][k].first, isl[i][k].second, isl[j][l].first, isl[j][l].second);
          mnv = min(mnv, dst);
        }
      }
    }
  }

  cout << (mnv - 1);
}
