#include <bits/stdc++.h>
using namespace std;

vector<int> v;
queue<int> q, b;
int bsum;

int main()
{
    int n, w, l;
    scanf("%d %d %d", &n, &w, &l);
    for(int i=0 ; i<n ; i++) {
        int t;
        scanf("%d", &t);
        q.push(t);
    }
    for(int i=0 ; i<w ; i++) b.push(0);
    
    int t = 0;
    while(!q.empty()) {
        bsum -= b.front();
        b.pop();
        
        int qf = q.front();
        if(b.size() < w && bsum + qf <= l) {
            b.push(qf);
            q.pop();
            bsum += qf;
        }
        else {
            b.push(0);
        }
        t++;
    }
    printf("%d", t + w);
}