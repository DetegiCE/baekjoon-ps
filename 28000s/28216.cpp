#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, q;
map<int, ll> x[200005], y[200005];
map<int, ll> xc[200005], yc[200005];
vector<int> xcv[200005], ycv[200005], xcvm[200005], ycvm[200005];
ll s;
int cx, cy;

int find_min(int dir, int fx, int d) {
    if(dir == 1) {
        auto lwb = lower_bound(xcvm[fx].begin(), xcvm[fx].end(), -d);
        if(lwb == xcvm[fx].end()) return -1;
        else return -(*lwb);
    }
    else {
        auto lwb = lower_bound(ycvm[fx].begin(), ycvm[fx].end(), -d);
        if(lwb == ycvm[fx].end()) return -1;
        else return -(*lwb);
    }
}

ll geti(int dir, int fx, int d1, int d2) {
    if(dir == 1) {
        if(xc[fx].size() == 0) return 0;
        
        int mnidx = find_min(1, fx, d1);
        int mxidx = find_min(1, fx, d2);
        
        if(mxidx == -1) return 0;
        if(mnidx == -1) return xc[fx][mxidx];
        
        return xc[fx][mxidx]-xc[fx][mnidx];
    }
    else {
        if(yc[fx].size() == 0) return 0;
        
        int mnidx = find_min(0, fx, d1);
        int mxidx = find_min(0, fx, d2);
        
        if(mxidx == -1) return 0;
        if(mnidx == -1) return yc[fx][mxidx];
        
        return yc[fx][mxidx]-yc[fx][mnidx];
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> q;
    cx = cy = 1;
    for(int i=0 ; i<n ; i++) {
        int xx, yy, w;
        cin >> xx >> yy >> w;
        x[xx][yy] += w;
        y[yy][xx] += w;
    }
    for(int i=1 ; i<=200000 ; i++) {
        ll prv = 0;
        for(auto xv: x[i]) {
            int xk = get<0>(xv);
            ll xkv = get<1>(xv);
            prv += xkv;
            xc[i][xk] = prv;
            xcv[i].push_back(xk);
            xcvm[i].push_back(-xk);
        }
        sort(xcvm[i].begin(), xcvm[i].end());
    }
    for(int i=1 ; i<=200000 ; i++) {
        ll prv = 0;
        for(auto xv: y[i]) {
            int xk = get<0>(xv);
            ll xkv = get<1>(xv);
            prv += xkv;
            yc[i][xk] = prv;
            ycv[i].push_back(xk);
            ycvm[i].push_back(-xk);
        }
        sort(ycvm[i].begin(), ycvm[i].end());
    }
    // for(int i=1 ; i<=10 ; i++) {
    //     cout << "xc " << i << '\n';
    //     for(auto xv: xc[i]) {
    //         int xk = get<0>(xv);
    //         ll xkv = get<1>(xv);
    //         cout << xk << ' ' << xkv << '\n';
    //     }
    // }
    // for(int i=1 ; i<=10 ; i++) {
    //     cout << "yc " << i << '\n';
    //     for(auto xv: yc[i]) {
    //         int xk = get<0>(xv);
    //         ll xkv = get<1>(xv);
    //         cout << xk << ' ' << xkv << '\n';
    //     }
    // }
    while(q--) {
        int d, v;
        cin >> d >> v;
        if(d == 0) {
            s += geti(0, cy, cx, cx+v);
            cx += v;
        }
        if(d == 1) {
            s += geti(1, cx, cy, cy+v);
            cy += v;
        }
        if(d == 2) {
            s += geti(0, cy, cx-v-1, cx-1);
            cx -= v;
        }
        if(d == 3) {
            s += geti(1, cx, cy-v-1, cy-1);
            cy -= v;
        }
        // cout << cx << ' ' << cy << ' ' << s << '\n';
    }
    cout << s;
}
