#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

#define MAX 103
#define INF 1e9

vector<int> path[MAX];
int cap[MAX][MAX], f[MAX][MAX], d[MAX][MAX];
int res, cnt;

void makePath(int st, int en, int val) {
    path[st].push_back(en);
    path[en].push_back(st);
    cap[st][en] = val;
}

void mcmf(int start, int end) {
    while (true) {
        vector<int> prev(MAX, -1);
        vector<int> dist(MAX, INF);
        vector<bool> vis(MAX, false);
        queue<int> q;

        q.push(start);
        dist[start] = 0;
        vis[start] = true;

        while (!q.empty()) {
            int qf = q.front();
            q.pop();

            vis[qf] = false;
            for (int i = 0; i < path[qf].size(); i++) {
                int nxt = path[qf][i];

                if (cap[qf][nxt] - f[qf][nxt] &&
                    dist[nxt] > dist[qf] + d[qf][nxt]) {
                    dist[nxt] = dist[qf] + d[qf][nxt];
                    prev[nxt] = qf;
                    if (!vis[nxt]) {
                        vis[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }

        if (prev[end] == -1) break;

        int flow = INF;
        for (int i = end; i != start; i = prev[i]) {
            flow = min(flow, cap[prev[i]][i] - f[prev[i]][i]);
        }
        for (int i = end; i != start; i = prev[i]) {
            res += flow * d[prev[i]][i];
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        cnt++;
    }
}

int calcLen(char a, char b) {
    if(b >= a) return b-a;
    else return 26-a+b;
}

int main()
{
    // 0, 1~50, 51~100, 101
    char ast[51], bst[51];
    int slen;
    scanf("%s", ast);
    scanf("%s", bst);
    slen = strlen(ast);
    for(int i=1 ; i<=slen ; i++) {
        makePath(0, i, 1);
        makePath(50+i, 101, 1);
    }
    for(int i=0 ; i<slen ; i++) {
        for(int j=0 ; j<slen ; j++) {
            makePath(i+1, j+51, 1);
            int c = calcLen(ast[i], bst[j]);
            //printf("%c %c %d\n", ast[i], bst[j], calcLen(ast[i], bst[j]));
            d[i+1][j+51] = c;
            d[j+51][i+1] = -c;
        }
    }
    mcmf(0, 101);
    printf("%d", res);
}