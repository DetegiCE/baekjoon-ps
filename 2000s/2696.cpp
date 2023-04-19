#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int m;
priority_queue<int> lpq;
priority_queue<int, vector<int>, greater<int> > rpq;

void f() {
    while(!lpq.empty()) lpq.pop();
    while(!rpq.empty()) rpq.pop();
    cin >> m;
    cout << m/2+1 << '\n';
    for(int i=1 ; i<=m ; i++) {
        int t;
        cin >> t;
        if(!lpq.empty() && lpq.top() > t) {
            rpq.push(lpq.top());
            lpq.pop();
            lpq.push(t);
        }
        else {
            rpq.push(t);
        }
        if(rpq.size() - lpq.size() >= 2) {
            lpq.push(rpq.top());
            rpq.pop();
        }
        if(i&1) {
            if(i>20 && i%20==1) cout << '\n';
            cout << rpq.top() << ' ';
        }
    }
    cout << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        f();
    }
}
