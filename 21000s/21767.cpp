#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define MAX(A,B) (A>B?A:B)

int n, k;
ll a, b, c, d;
priority_queue<ll> qa, qb, qc, qd;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> k;
    cin >> a >> b >> c >> d;
    for(int i=0 ; i<n ; i++) {
        char t;
        ll v;
        cin.ignore();
        cin >> t >> v;
        if(t == 'A') qa.push(v);
        if(t == 'B') qb.push(v);
        if(t == 'C') qc.push(v);
        if(t == 'D') qd.push(v);
    }
    while(k--) {
        ld mxv = 0;
        ll cmxv = 0;
        int mxi = 0;
        if(!qa.empty() && mxv < (ld)(qa.top())/(ld)a) {
            mxv = (ld)(qa.top())/(ld)a;
            cmxv = qa.top();
            mxi = 1;
        }
        if(!qb.empty() && mxv < (ld)(qb.top())/(ld)b) {
            mxv = (ld)(qb.top())/(ld)b;
            cmxv = qb.top();
            mxi = 2;
        }
        if(!qc.empty() && mxv < (ld)(qc.top())/(ld)c) {
            mxv = (ld)(qc.top())/(ld)c;
            cmxv = qc.top();
            mxi = 3;
        }
        if(!qd.empty() && mxv < (ld)(qd.top())/(ld)d) {
            mxv = (ld)(qd.top())/(ld)d;
            cmxv = qd.top();
            mxi = 4;
        }
        
        cout << (char)(mxi+64) << ' ' << cmxv << '\n';
        switch(mxi) {
            case 1:
                a += cmxv;
                qa.pop();
                break;
            case 2:
                b += cmxv;
                qb.pop();
                break;
            case 3:
                c += cmxv;
                qc.pop();
                break;
            case 4:
                d += cmxv;
                qd.pop();
                break;
        }
    }
}
