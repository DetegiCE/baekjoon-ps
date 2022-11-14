#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)

int n;
int cnt = 0;
map<string, int> mp;
string mpr[400004];

vector<int> path[400004];
int ind[400004];

int main()
{
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        string a, b;
        cin >> a >> b;
        
        auto aidx = mp.find(a);
        auto bidx = mp.find(b);
        int aval, bval;
        if(aidx != mp.end()) aval = aidx->second;
        else {
            cnt++;
            aval = cnt;
            mp.insert({a, aval});
            mpr[aval] = a;
        }
        if(bidx != mp.end()) bval = bidx->second;
        else {
            cnt++;
            bval = cnt;
            mp.insert({b, bval});
            mpr[bval] = b;
        }
        
        path[aval].PB(bval);
        ind[bval]++;
    }
    
    int pcnt = 0;
    queue<int> q, nq;
    vector<string> vst;
    vector<string> vans;
    
    for(int i=1 ; i<=cnt ; i++) {
        if(ind[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        while(!q.empty()) {
            int qf = q.front();
            q.pop();
            
            for(auto i: path[qf]) {
                ind[i]--;
                if(ind[i] == 0) {
                    nq.push(i);
                }
            }
            vst.PB(mpr[qf]);
            pcnt++;
        }
        while(!nq.empty()) {
            q.push(nq.front());
            nq.pop();
        }
        sort(vst.begin(), vst.end());
        for(auto i: vst) {
            vans.PB(i);
        }
        vst.clear();
    }
    if(pcnt < cnt) {
        cout << -1;
    }
    else {
        for(auto i: vans) {
            cout << i << '\n';
        }
    }
}