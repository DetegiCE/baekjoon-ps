#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
#define MP(A,B) make_pair(A,B)

int n, x, mnv = 100005;
int t[100005];
priority_queue<pii> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> x;
    for(int i=0 ; i<n ; i++) cin >> t[i];
    
    int lef = 1;
    int rig = n;
    mnv = n;
    while(lef <= rig) {
        int mid = (lef + rig) / 2;
        // cout << lef << ' ' << rig << ' ' << mid << '\n';
        
        int mxv = 0;
        while(!pq.empty()) pq.pop();
        for(int i=1 ; i<=mid ; i++) pq.push(MP(0, i));
        for(int i=0 ; i<n ; i++) {
            pii pf = pq.top();
            pq.pop();
            pq.push(MP(pf.first-t[i], pf.second));
            mxv = max(mxv, -pf.first+t[i]);
        }
        if(mxv > x) {
            lef = mid + 1;
        }
        else {
            rig = mid - 1;
        }
    }
    cout << rig + 1;
}
