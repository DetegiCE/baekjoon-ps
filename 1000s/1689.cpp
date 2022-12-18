#include<bits/stdc++.h>
using namespace std;
#define MP(A,B) make_pair(A,B)

typedef pair<int,int> pii;
priority_queue<pii> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        // 좌표는 -, 열림 -1, 닫힘 1
        pq.push(MP(-a, -1));
        pq.push(MP(-b, 1));
    }
    int mxv = -1;
    int cur = 0;
    while(!pq.empty()) {
        pii qt = pq.top();
        pq.pop();
        cur -= qt.second;
        mxv = max(mxv, cur);
    }
    cout << mxv;
}