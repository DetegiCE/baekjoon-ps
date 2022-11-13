#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)
#define PF(A) push_front(A)
typedef long long ll;
    
int n, m;
int ind[32003];
vector<int> path[32003];
priority_queue<int, vector<int>, greater<int> > pq;
    
int main()
{
    INP;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++) {
        int a, b;
        cin >> a >> b;
        path[a].PB(b);
        ind[b]++;
    }
    
    int cnt = 0;
    for(int i=1 ; i<=n ; i++){
        if(ind[i] == 0) {
            pq.push(i);
        }
    }
    while(!pq.empty()) {
        int qt = pq.top();
        pq.pop();
        cout << qt << ' ';
        
        for(auto i: path[qt]) {
            ind[i]--;
            if(ind[i] == 0) {
                pq.push(i);
            }
        }
    }
}