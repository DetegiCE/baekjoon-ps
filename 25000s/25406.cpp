#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n;
int a[300005];
priority_queue<int> pq[300005];
set<pii> cnt;
set<pii> s;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        cin >> a[i];
        pq[a[i]].push(-i);
    }
    for(int i=1 ; i<=n ; i++) {
        if(pq[i].size() > 0) {
            cnt.insert(pii(pq[i].size(), i));
            s.insert(pii(-pq[i].top(), i));
        }
    }
    
    if((*cnt.rbegin()).first > (n+1)/2) {
        cout << "-1";
        return 0;
    }
    
    int bef = 0;
    while(n--) {
        // cout << "\n[" << n << "]: " << bef << '\n';
        // cout << (*cnt.rbegin()).first << ' ' << (*cnt.rbegin()).second << '\n';
        // cout << pq[(*cnt.rbegin()).second].size() << '\n';
        // cout << pq[(*cnt.rbegin()).second].top() << '\n';
        if((*cnt.rbegin()).first > (n+1)/2) {
            // cout << "A\n";
            int ncnt = (*cnt.rbegin()).first;
            int num = (*cnt.rbegin()).second;
            int val = -(pq[num].top());
            
            cout << val << ' ';
            bef = num;
            pq[num].pop();
            
            cnt.erase(cnt.find(pii(ncnt, num)));
            s.erase(s.find(pii(val, num)));
            if(ncnt > 1) {
                s.insert(pii(-pq[num].top(), num));
                cnt.insert(pii(ncnt-1, num));
            }
        }
        else {
            // cout << "B\n";
            auto it = s.begin();
            
            while((*it).second == bef && it != s.end()) it++;
            int val = (*it).first;
            int num = (*it).second;
            
            // cout << '\n';
            cout << val << ' ';
            s.erase(s.find(pii(val, num)));
            cnt.erase(cnt.find(pii(pq[num].size(), num)));
            bef = num;
            pq[num].pop();
            
            if(pq[num].size() > 0) {
                cnt.insert(pii(pq[num].size(), num));
                s.insert(pii(-pq[num].top(), num));
            }
        }
    }
}
