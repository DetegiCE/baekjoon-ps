#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 987654321
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;

typedef struct player {
    int color;
    int size;
} PLAYER;

vector<int> tot, ctot;
vector<int> clr[200001], cclr[200001];
vector<PLAYER> vp;

int main()
{
    // INP;
    ll n;
    
    cin >> n;
    
    for(int i=0 ; i<n ; i++) {
        int c, s;
        cin >> c >> s;
        tot.PB(s);
        clr[c].PB(s);
        
        PLAYER np = {c, s};
        vp.PB(np);
    }
    sort(tot.begin(), tot.end());
    ctot.PB(tot[0]);
    for(int i=1 ; i<n ; i++) {
        ctot.PB(ctot[i-1]+tot[i]);
    }
    
    for(int i=1 ; i<=n ; i++) {
        if(clr[i].size() == 0) continue;
        sort(clr[i].begin(), clr[i].end());
        cclr[i].PB(clr[i][0]);
        for(int j=1 ; j<clr[i].size() ; j++) {
            cclr[i].PB(cclr[i][j-1]+clr[i][j]);
        }
    }
    
    for(int i=0 ; i<n ; i++) {
        int curc = vp[i].color;
        int curs = vp[i].size;
        
        int tval = ctot[lower_bound(tot.begin(), tot.end(), curs) - tot.begin() - 1];
        int cval = cclr[curc][lower_bound(clr[curc].begin(), clr[curc].end(), curs) - clr[curc].begin() - 1];
        
        cout << tval - cval << '\n';
    }
    
}