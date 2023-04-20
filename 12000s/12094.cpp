#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(A) A.begin(), A.end()

string s, t;
set<string> st;
queue<string> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> s >> t;
    q.push(t);
    st.insert(t);
    
    int sl = s.length();
    while(!q.empty()) {
        string qf = q.front();
        q.pop();
        
        if(qf == s) {
            cout << "1";
            return 0;
        }
        
        int qfl = qf.length();
        if(qfl < sl) break;
        if(qf[qfl-1] == 'A') {
            string na = qf.substr(0, qfl-1);
            if(st.find(na) == st.end()) {
                q.push(na);
                st.insert(na);
            }
        }
        if(qf[qfl-1] == 'B') {
            string nb = qf.substr(0, qfl-1);
            reverse(ALL(nb));
            if(st.find(nb) == st.end()) {
                q.push(nb);
                st.insert(nb);
            }
        }
    }
    cout << "0";
    return 0;
}
