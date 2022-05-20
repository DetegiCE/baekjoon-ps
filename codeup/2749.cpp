// not solved
#include<cstdio>
#include<queue>
using namespace std;

typedef struct pizza {
    int index;
    char time;
    int endtime;

    bool operator < (const pizza &p) const {
        if(endtime == p.endtime) {
            if(time == p.time) {
                return index > p.index;
            }
            return time > p.time;
        }
        return endtime > p.endtime;
    }
} PIZZA;

int n;
priority_queue<PIZZA> pq;

int bend, cend, dend, eend;

int main()
{
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++) {
        int t, nt;
        char p;
        scanf("%d %c", &t, &p);
        if(p == 'b') {
            if(bend == 0) {
                nt = t + 5;
                bend = nt;
            }
            else {
                nt = bend + 5;
                bend += 5;
            }
        }
        if(p == 'c') {
            if(cend == 0) {
                nt = t + 7;
                cend = nt;
            }
            else {
                nt = cend + 7;
                cend += 7;
            }
        }
        if(p == 'd') {
            if(dend == 0) {
                nt = t + 8;
                dend = nt;
            }
            else {
                nt = dend + 8;
                dend += 8;
            }
        }
        if(p == 'e') {
            if(eend == 0) {
                nt = t + 10;
                eend = nt;
            }
            else {
                nt = eend + 10;
                eend += 10;
            }
        }
        PIZZA np = {i, p, nt};
        pq.push(np);
    }
    while(!pq.empty()) {
        printf("%d ", pq.top().index);
        pq.pop();
    }
}