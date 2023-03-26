#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> ti;

int l, r, c;
int sx, sy, sz, ex, ey, ez;
string mapp[33][33];
int vis[33][33][33];

int dx[6] = {-1, 0, 0, 0, 0, 1};
int dy[6] = {0, -1, 1, 0, 0, 0};
int dz[6] = {0, 0, 0, -1, 1, 0};

inline bool inborder(int x, int y, int z) {
  return 0 <= x && x < l && 0 <= y && y < r && 0 <= z && z < c;
}

void f() {
  for (int i = 0; i < 31; i++) {
    for (int j = 0; j < 31; j++) {
      for (int k = 0; k < 31; k++) {
        vis[i][j][k] = 0;
      }
    }
  }
  
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < r; j++) {
      cin >> mapp[i][j];
      for (int k = 0; k < c; k++) {
        if (mapp[i][j][k] == 'S') {
          sx = i;
          sy = j;
          sz = k;
        }
        if (mapp[i][j][k] == 'E') {
          ex = i;
          ey = j;
          ez = k;
        }
      }
    }
    cin.ignore();
  }
  ti st = make_tuple(sx, sy, sz);
  queue<ti> q;
  q.push(st);
  vis[sx][sy][sz] = 1;
  while (!q.empty()) {
    ti qf = q.front();
    q.pop();
    int fx = get<0>(qf);
    int fy = get<1>(qf);
    int fz = get<2>(qf);

    // cout << fx << ' ' << fy << ' ' << fz << '\n';

    for (int i = 0; i < 6; i++) {
      int nx = fx + dx[i];
      int ny = fy + dy[i];
      int nz = fz + dz[i];
      if (inborder(nx, ny, nz) && vis[nx][ny][nz] == 0 &&
          mapp[nx][ny][nz] != '#') {
        vis[nx][ny][nz] = vis[fx][fy][fz] + 1;
        q.push(make_tuple(nx, ny, nz));
      }
    }
  }

  if (vis[ex][ey][ez] == 0) {
    cout << "Trapped!\n";
  } else {
    cout << "Escaped in " << vis[ex][ey][ez] - 1 << " minute(s).\n";
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  while (1) {
    cin >> l >> r >> c;
    if (l == 0)
      break;
    f();
  }
}
