#include<cstdio>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

#define MIN(A,B) (A>B?B:A)

int edge[30][30];
int dis[30], n, m;
queue<char> q;
stack<char> s;
char from[30], st, en;

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0 ; i<26 ; i++) {
        for(int j=0 ; j<26 ; j++) {
            edge[i][j] = 1e9;
        }
    }
    for(int i=0 ; i<m ; i++) {
        char a, b;
        int c;
        scanf(" %c %c %d", &a, &b, &c);
        edge[a-'A'][b-'A'] = MIN(edge[a-'A'][b-'A'], c);
        edge[b-'A'][a-'A'] = MIN(edge[b-'A'][a-'A'], c);
    }
    scanf(" %c %c", &st, &en);

    for(int i=0 ; i<26 ; i++) dis[i] = 1e9;
    dis[st-'A'] = 0;
    q.push(st);
    while(!q.empty()) {
        char qf = q.front();
        q.pop();
        for(int i=0 ; i<26 ; i++) {
            int nxt = edge[qf-'A'][i];
            if(nxt < 1e9 && dis[i] > dis[qf-'A'] + nxt) {
                dis[i] = dis[qf-'A'] + nxt;
                from[i] = qf;
                q.push(i+'A');
            }
        }
    }
    if(dis[en-'A'] == 1e9) {
        puts("-1");
        return 0;
    }
    printf("%d\n", dis[en-'A']);

    char cur = en;
    while(from[cur-'A'] != st) {
        s.push(from[cur-'A']);
        cur = from[cur-'A'];
    }
    printf("%c\n", st);
    while(!s.empty()) {
        printf("%c\n", s.top());
        s.pop();
    }
    printf("%c\n", en);
}