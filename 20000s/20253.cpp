#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ABS(A) (A>0?A:-A)
#define MAX(A,B) (A>B?A:B)
#define ALL(A) A.begin(),A.end()
#define MOD 1000000007

int n;
int ncnt, pcnt, zcnt;
vector<ll> neg, pos;
ll mnv, mxv;

ll modulo(ll a) {
    ll v = a - MOD * (a/MOD);
    if(v < 0) return MOD + v;
    else return v;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        ll t;
        cin >> t;
        if(t > 0) {
            pos.push_back(t);
            pcnt++;
        }
        else if(t < 0) {
            neg.push_back(t);
            ncnt++;
        }
        else zcnt++;
    }
    
    if(!pos.empty()) sort(ALL(pos));
    if(!neg.empty()) sort(ALL(neg));
    
    if(pcnt == n) {
        for(int i=1 ; i<n ; i++) {
            mnv += pos[0] * pos[i];
            mnv = modulo(mnv);
        }
        for(int i=0 ; i<n-1 ; i++) {
            mxv += pos[n-1] * pos[i];
            mxv = modulo(mxv);
        }
        cout << mnv << ' ' << mxv;
    }
    else if(zcnt == n) {
        cout << "0 0";
    }
    else if(ncnt == n) {
        for(int i=1 ; i<n ; i++) {
            mnv += neg[0] * neg[i];
            mnv = modulo(mnv);
        }
        for(int i=0 ; i<n-1 ; i++) {
            mxv += neg[n-1] * neg[i];
            mxv = modulo(mxv);
        }
        cout << mxv << ' ' << mnv;
    }
    else if(pcnt + zcnt == n) {
        for(int i=0 ; i<pcnt-1 ; i++) {
            mxv += pos[pcnt-1] * pos[i];
            mxv = modulo(mxv);
        }
        cout << "0 " << mxv;
    }
    else if(ncnt + zcnt == n) {
        for(int i=1 ; i<ncnt ; i++) {
            mxv += neg[0] * neg[i];
            mxv = modulo(mxv);
        }
        cout << "0 " << mxv;
    }
    else {
        // -10 -5 -5 -2 -1
        // 1 1 2 5 6
        for(int i=0 ; i<pcnt ; i++) {
            mnv += neg[0] * pos[i];
            mnv = modulo(mnv);
        }
        for(int i=1 ; i<ncnt ; i++) {
            mnv += pos[pcnt-1] * neg[i];
            mnv = modulo(mnv);
        }
        for(int i=0 ; i<pcnt-1 ; i++) {
            mxv += pos[pcnt-1] * pos[i];
            mxv = modulo(mxv);
        }
        for(int i=1 ; i<ncnt ; i++) {
            mxv += neg[0] * neg[i];
            mxv = modulo(mxv);
        }
        if(zcnt == 0) {
            mxv += neg[ncnt-1] * pos[0];
            mxv = modulo(mxv);
        }
        cout << mnv << ' ' << mxv << '\n';
    }
}
