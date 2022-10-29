#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;

int n, m;
int price[1001];
map<int,int> path[1001];
int from[1001];
stack<int> stk;

int dijk(int st, int en) {
    for(int i=1 ; i<=n ; i++) price[i] = INF;
    priority_queue<pii> pq;
    price[st] = 0;
    pq.push(MP(0, st));
    while(!pq.empty()) {
        int cdst = (-1) * pq.top().first;
        int cpos = pq.top().second;
        pq.pop();
        
        for(auto i: path[cpos]) {
            int nxt = i.first;
            int ndst = i.second;
            
            if(ndst + cdst < price[nxt]) {
                price[nxt] = ndst + cdst;
                from[nxt] = cpos;
                pq.push(MP(-ndst-cdst, nxt));
            }
        }
    }
    return price[en];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0 ; i<m ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        auto mp = path[a].find(b);
        if(mp == path[a].end()) {
            path[a].insert({b, c});
        }
        else {
            mp->second = min(mp->second, c);
        }
    }
    
    int st, en;
    cin >> st >> en;
    cout << dijk(st, en) << '\n';
    
    int apos = en;
    while(apos != st) {
        stk.push(apos);
        apos = from[apos];
    }
    stk.push(st);
    cout << stk.size() << '\n';
    while(!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }
}