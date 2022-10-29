#include<bits/stdc++.h>
using namespace std;
#define INF 98765

int n;
int pop[12];
vector<int> lnk[12];
vector<int> a, b;

int dst[12][12];

bool lnked() {
    bool visa[12] = {false};
    bool visb[12] = {false};
    int plce[12] = {0};
    bool isa = false, isb = false;
    queue<int> qa, qb;
    for(int i=1 ; i<=n ; i++) visa[i] = visb[i] = false;
    
    for(auto i: a) plce[i] = 1;
    for(auto i: b) plce[i] = 2;
    
    if(a.size() == 1) isa = true;
    else {
        qa.push(a[0]);
        while(!qa.empty()) {
            int qf = qa.front();
            qa.pop();
            
            visa[qf] = true;
            for(auto i: lnk[qf]) {
                if(!visa[i] && plce[i] == 1) qa.push(i);
            }
        }
        for(auto i: a) {
            if(!visa[i]) return false;
        }
        isa = true;
    }
    
    if(b.size() == 1) isb = true;
    else {
        qb.push(b[0]);
        while(!qb.empty()) {
            int qf = qb.front();
            qb.pop();
            
            visb[qf] = true;
            for(auto i: lnk[qf]) {
                if(!visb[i] && plce[i] == 2) qb.push(i);
            }
        }
        for(auto i: b) {
            if(!visb[i]) return false;
        }
        isb = true;
    }
    
    return isa & isb;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=1 ; i<=n ; i++) cin >> pop[i];
    for(int i=1 ; i<=n ; i++) {
        int t;
        cin >> t;
        for(int j=0 ; j<t ; j++) {
            int s;
            cin >> s;
            lnk[i].push_back(s);
        }
    }
    if(n == 2) {
        cout << abs(pop[1]-pop[2]);
        return 0;
    }
    
    int mndf = INF;
    for(int i=1 ; i<(1<<(n-1)) ; i++) {
        a.clear();
        b.clear();
        for(int j=0 ; j<n ; j++) {
            if(i & (1<<j)) a.push_back(j+1);
            else b.push_back(j+1);
        }
        if(lnked()) {
            int asum = 0, bsum = 0;
            for(int j=0 ; j<n ; j++) {
                if(i & (1<<j)) asum += pop[j+1];
                else bsum += pop[j+1];
            }
            // cout << i << ' ' << asum << ' ' << bsum << '\n';
            mndf = min(mndf, abs(asum-bsum));
        }
    }
    
    if(mndf == INF) cout << -1;
    else cout << mndf;
}