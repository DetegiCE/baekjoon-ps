#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)
typedef long long ll;

int ntos(string s) {
    int h = 0;
    for(int i=2 ; i<s.length() ; i++) {
        h *= 10;
        h += (s[i]-48);
    }
    h += 1000 * (s[0] - 65);
    return h;
}

int main()
{
    INP;
    
    int n;
    vector<int> v, w;
    map<int,int> mp;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<5 ; j++) {
            string s;
            cin >> s;
            int no = ntos(s);
            v.PB(no);
            w.PB(no);
        }
    }
    sort(w.begin(), w.end());
    for(int i=0 ; i<n*5 ; i++) {
        mp.insert({w[i], i});
    }
    for(int i=0 ; i<n*5 ; i++) {
        v[i] = mp[v[i]];
    }
    
    stack<int> st;
    int cur = 0;
    for(auto i: v) {
        while(!st.empty() && st.top() == cur) {
            cur++;
            st.pop();
        }
        if(i == cur) {
            cur++;
            continue;
        }
        else {
            st.push(i);
        }
    }
    while(!st.empty() && st.top() == cur) {
        cur++;
        st.pop();
    }
    if(st.empty()) cout << "GOOD";
    else cout << "BAD";
}