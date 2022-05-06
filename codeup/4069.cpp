#include<cstdio>
#include<queue>
using namespace std;

int n, cnt[100001];
queue<int> q;

int main()
{
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++) cnt[i] = -1;
    cnt[n] = 0;
    q.push(n);
    while(!q.empty()) {
        int qf = q.front(); q.pop();
        if(qf == 1) {
            printf("%d", cnt[1]);
            return 0;
        }
        if(qf % 5 == 0 && cnt[qf/5] == -1) {
            q.push(qf/5);
            cnt[qf/5] = cnt[qf] + 1;
        }
        if(qf % 2 == 0 && cnt[qf/2] == -1) {
            q.push(qf/2);
            cnt[qf/2] = cnt[qf] + 1;
        }
        if(cnt[qf-1] == -1) {
            q.push(qf-1);
            cnt[qf-1] = cnt[qf] + 1;
        }
        
    }
}
