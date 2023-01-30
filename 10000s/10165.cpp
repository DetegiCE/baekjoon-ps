#include<bits/stdc++.h>
using namespace std;
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
#define ALL(A) (A).begin(), (A).end()
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;

int n, m;
vector<ppi> v;
bool chk[500005];

bool comp(ppi a, ppi b) {
    if(a.first.first == b.first.first) 
        return a.first.second > b.first.second;
    return a.first.first < b.first.first;
}

int main() 
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i=0 ; i<m ; i++) {
        int x, y;
        cin >> x >> y;
        if(x < y) {
            v.PB(MP(MP(x,y),i));
            v.PB(MP(MP(x+n,y+n),i));
        }
        else {
            v.PB(MP(MP(x,y+n),i));
        }
    }
    sort(ALL(v), comp);
    int lef = 0, rig = 0;
    for(auto k: v) {
        int st = k.first.first;
        int en = k.first.second;
        int idx = k.second;
        if(chk[idx]) continue;
        if(lef <= st && en <= rig) {
            chk[idx] = true;
            continue;
        }
        lef = st;
        rig = en;
    }
    for(int i=0 ; i<m ; i++) {
        if(!chk[i]) cout << i+1 << ' ';
    }
}
