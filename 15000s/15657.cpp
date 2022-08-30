#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
int prt[8];

void f(int cur) {
    if(cur == m) {
        for(int i=0 ; i<m ; i++) {
            printf("%d ", v[prt[i]]);
        }
        puts("");
        return;
    }
    for(int i=(cur==0?0:prt[cur-1]) ; i<n ; i++) {
        if(i && v[i-1] == v[i]) {
            continue;
        }
        prt[cur] = i;
        f(cur+1);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0 ; i<n ; i++) {
        int t;
        scanf("%d", &t);
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    f(0);
}