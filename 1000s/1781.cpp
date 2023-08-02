#include<bits/stdc++.h>
using namespace std;

int n, s;
priority_queue<int> pq;
vector<int> v[200002];

int main() 
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i=n ; i>=1 ; i--) {
        for(auto j: v[i]) {
            pq.push(j);
        }
        if(!pq.empty()) {
            s += pq.top();
            pq.pop();
        }
    }
    cout << s;
}
