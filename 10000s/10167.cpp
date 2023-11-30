#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;

typedef struct gold {
    int x;
    int y;
    int w;
} GOLD;

int n;
vector<GOLD> v;
vector<int> x, y;
map<int,int> xpos, ypos;
vector<pii> ycomp[3003];

bool cmp(GOLD a, GOLD b) {
    if(a.y == b.y) return a.x < b.x;
    else return a.y < b.y;
}

typedef struct tree {
    ll left, right, tot, sum;
} TREE;

TREE t[12004];

ll ans;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        GOLD g;
        cin >> g.x >> g.y >> g.w;
        v.push_back(g);
        x.push_back(g.x);
        y.push_back(g.y);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    int xcnt = 0, ycnt = 0;
    xpos[x[0]] = 0;
    ypos[y[0]] = 0;
    for(int i=1 ; i<n ; i++) {
        if(x[i-1] != x[i]) {
            xpos[x[i]] = ++xcnt;
        }
        if(y[i-1] != y[i]) {
            ypos[y[i]] = ++ycnt;
        }
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0 ; i<n ; i++) {
        v[i].x = xpos[v[i].x];
        v[i].y = ypos[v[i].y];
        ycomp[v[i].y].push_back(pii(v[i].x, v[i].w));
    }
    
    int bn = 1;
    while(bn < n) bn *= 2;
    for(int i=0 ; i<=ycnt ; i++) {
        for(int j=1 ; j<=bn+n ; j++) {
            t[j].left = 0;
            t[j].right = 0;
            t[j].tot = 0;
            t[j].sum = 0;
        }
        for(int j=i ; j<=ycnt ; j++) {
            int sz = ycomp[j].size();
            for(int k=0 ; k<sz ; k++) {
                int curx = bn + ycomp[j][k].first;
                int curw = ycomp[j][k].second;
                
                t[curx].left += curw;
                t[curx].right += curw;
                t[curx].tot += curw;
                t[curx].sum += curw;
                while(curx) {
                    curx /= 2;
                    t[curx].left = max(t[curx*2].sum + t[curx*2+1].left, t[curx*2].left);
                    t[curx].right = max(t[curx*2].right + t[curx*2+1].sum, t[curx*2+1].right);
                    t[curx].sum += curw;
                    t[curx].tot = max(max(max(max(t[curx].right, t[curx].left), t[curx*2].tot), t[curx*2+1].tot), t[curx*2].right+t[curx*2+1].left);
                }
            }
            ans = max(ans, t[1].tot);
        }
    }
    cout << ans;
}
