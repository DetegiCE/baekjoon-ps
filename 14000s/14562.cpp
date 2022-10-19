#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

typedef struct scores {
    int a;
    int b;
    int count;
    
    scores(int a, int b, int count): a(a), b(b), count(count) {}
} SCORE;

queue<SCORE> q;

void sol() {
    while(!q.empty()) q.pop();
    int s, t;
    cin >> s >> t;
    
    q.push(scores(s, t, 0));
    while(!q.empty()) {
        SCORE qf = q.front();
        q.pop();
        
        int qfa = qf.a;
        int qfb = qf.b;
        int qfc = qf.count;
        if(qfa == qfb) {
            cout << qfc << '\n';
            return;
        }
        if(qfa * 2 <= qfb + 3) {
            q.push(scores(qfa*2, qfb+3, qfc+1));
        }
        if(qfa+1 <= qfb) {
            q.push(scores(qfa+1, qfb, qfc+1));
        }
    }
}

int main()
{
    INP;
    
    int c;
    cin >> c;
    while(c--) {
        sol();
    }
}