#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct build {
    int time;
    int curcomp; // 선 완성된 빌딩 수
    int need;
    int elap; // 완성에 걸린 시간
    vector<int> next;
};

build b[501];
queue<int> q;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++) {
        int t;
        scanf("%d", &b[i].time);
        int cnt = 0;
        while(1) {
            scanf("%d", &t);
            if(t == -1) break;
            cnt++;
            b[t].next.push_back(i);
            b[i].need++;
        }
        if(cnt == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int qf = q.front(); q.pop();
        b[qf].elap += b[qf].time;
        for(int i=0 ; i<b[qf].next.size() ; i++) {
            int nxt = b[qf].next[i];
            b[nxt].curcomp++;
            b[nxt].elap = max(b[nxt].elap, b[qf].elap);
            if(b[nxt].curcomp == b[nxt].need) {
                q.push(nxt);
            }
        }
    }
    for(int i=1 ; i<=n ; i++) {
        printf("%d\n", b[i].elap);
    }
}