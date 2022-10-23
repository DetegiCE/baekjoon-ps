#include<bits/stdc++.h>
using namespace std;

typedef pair<string, int> psi;

string n;
int k, nlen;

queue<psi> q;
int mxv = -1;

bool vis[1000002][12];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    nlen = n.length();
    q.push(make_pair(n, 0));
    vis[stoi(n)][0] = true;
    
    while(!q.empty()) {
        psi qf = q.front();
        string qfs = qf.first;
        int qfc = qf.second;
        q.pop();
        
        for(int i=0 ; i<nlen ; i++) {
            for(int j=i+1 ; j<nlen ; j++) {
                if(i == 0 && qfs[j] == '0') continue;
                string nxs = qfs;
                char t = nxs[i];
                nxs[i] = nxs[j];
                nxs[j] = t;
                int nxi = stoi(nxs);
                if(vis[nxi][qfc+1]) continue;
                vis[nxi][qfc+1] = true;
                if(qfc + 1 == k) {
                    mxv = max(mxv, stoi(nxs));
                }
                else q.push(make_pair(nxs, qfc+1));
            }
        }    
    }
    
    cout << mxv;
}