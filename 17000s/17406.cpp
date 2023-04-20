#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using t3i = tuple<int,int,int>;
#define F first
#define S second

int n, m, k;
int a[52][52];
vector<t3i> v;
vector<int> o;
int mn;

void rrotate(int d) {
    int r = get<0>(v[d]);
    int c = get<1>(v[d]);
    int s = get<2>(v[d]);
    
    for(int i=1 ; i<=s ; i++) {
        vector<pii> cr;
        for(int j=0 ; j<i*2 ; j++) cr.push_back(pii(r-i, c-i+j));
        for(int j=0 ; j<i*2 ; j++) cr.push_back(pii(r-i+j, c+i));
        for(int j=0 ; j<i*2 ; j++) cr.push_back(pii(r+i, c+i-j));
        for(int j=0 ; j<i*2 ; j++) cr.push_back(pii(r+i-j, c-i));
        
        int tr = cr[0].F;
        int tc = cr[0].S;
        int tv = a[tr][tc];
        for(int j=1 ; j<=i*8-1 ; j++) {
            int crr = cr[j].F;
            int crc = cr[j].S;
            int csr = cr[j-1].F;
            int csc = cr[j-1].S;
            a[csr][csc] = a[crr][crc];
        }
        a[cr[i*8-1].F][cr[i*8-1].S] = tv;
    }
}

void rotate(int d) {
    int r = get<0>(v[d]);
    int c = get<1>(v[d]);
    int s = get<2>(v[d]);
    
    for(int i=1 ; i<=s ; i++) {
        vector<pii> cr;
        for(int j=0 ; j<i*2 ; j++) cr.push_back(pii(r-i, c-i+j));
        for(int j=0 ; j<i*2 ; j++) cr.push_back(pii(r-i+j, c+i));
        for(int j=0 ; j<i*2 ; j++) cr.push_back(pii(r+i, c+i-j));
        for(int j=0 ; j<i*2 ; j++) cr.push_back(pii(r+i-j, c-i));
        
        int tr = cr[i*8-1].F;
        int tc = cr[i*8-1].S;
        int tv = a[tr][tc];
        for(int j=i*8-1 ; j>0 ; j--) {
            int crr = cr[j].F;
            int crc = cr[j].S;
            int csr = cr[j-1].F;
            int csc = cr[j-1].S;
            a[crr][crc] = a[csr][csc];
        }
        a[cr[0].F][cr[0].S] = tv;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    mn = 10000;
    cin >> n >> m >> k;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            cin >> a[i][j];
        }
    }
    for(int i=0 ; i<k ; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        v.push_back(t3i(r, c, s));
        o.push_back(i);
    }
    
    do {
        for(int i=0 ; i<k ; i++) {
            rotate(o[i]);
        }
        for(int i=1 ; i<=n ; i++) {
            int ts = 0;
            for(int j=1 ; j<=m ; j++) {
                ts += a[i][j];
            }
            mn = min(mn, ts);
        }
        for(int i=k-1 ; i>=0 ; i--) {
            rrotate(o[i]);
        }
    } while(next_permutation(o.begin(), o.end()));
    
    cout << mn;
}

