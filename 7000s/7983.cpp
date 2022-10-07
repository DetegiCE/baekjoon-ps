#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> v;

bool compare(pii a, pii b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    else return a.first > b.first;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(b, a));
    }
    
    sort(v.begin(), v.end(), compare);
    
    int curtime = v[0].first;
    for(int i=0 ; i<n ; i++) {
        if(curtime <= v[i].first)
            curtime -= v[i].second;
        else curtime = v[i].first - v[i].second;
    }
    printf("%d", curtime>=0?curtime:-1);
}