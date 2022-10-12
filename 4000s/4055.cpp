#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int t;
vector<pii> v;

void sol(int a) {
    v.clear();
    for(int i=0 ; i<t ; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        s *= 2;
        e *= 2;
        v.push_back(make_pair(s, e));
    }
    
    int cnt = 0;
    for(int i=16 ; i<48 ; i++) {
        int idx = -1;
        int tim = 49;
        for(int j=0 ; j<t ; j++) {
            if(v[j].first <= i && i < v[j].second && v[j].second < tim) {
                idx = j;
                tim = v[j].second;
            }
        }
        if(idx >= 0) {
            cnt++;
            v[idx].first = 48;
        }
    }
    printf("On day %d Emma can attend as many as %d parties.\n", a, cnt);
}

int main()
{
    for(int i=1 ;; i++) {
        scanf("%d", &t);
        if(t == 0) break;
        sol(i);
    }
}