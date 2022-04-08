#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

#define mp(A, B) make_pair(A, B)

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
vector<pip> v;

int n;
int arr[501][501];
int mov[501][501];
bool vis[501][501];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int dfs(int x, int y) {
    if (mov[x][y]) return mov[x][y];
    mov[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (0 < newx && newx <= n && 0 < newy && newy <= n &&
            arr[x][y] < arr[newx][newy]) {
            mov[x][y] = max(mov[x][y], dfs(newx, newy) + 1);
        }
    }
    return mov[x][y];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
            v.push_back(mp(arr[i][j], mp(i, j)));
        }
    }
    sort(v.begin(), v.end());
    int mx = 1;
    for (auto &i : v) {
        int posx = i.second.first;
        int posy = i.second.second;
        mx = max(mx, dfs(posx, posy));
    }
    printf("%d", mx);
}