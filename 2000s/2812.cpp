#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)
typedef long long ll;

int a[500005];
    
int main()
{
    INP;
    
    int n, k, p;
    string s;
    stack<int> st;
    cin >> n >> k;
    p = k;
    cin >> s;
    for(int i=0 ; i<n ; i++) a[i] = s[i] - 48;
    for(int i=0 ; i<n ; i++) {
        if(st.empty()) st.push(a[i]);
        else {
            if(st.top() >= a[i]) st.push(a[i]);
            else {
                while(!st.empty() && k > 0 && st.top() < a[i]) {
                    st.pop();
                    k--;
                }
                st.push(a[i]);
            }
        }
    }
    while(k) {
        st.pop();
        k--;
    }
    vector<int> ans;
    while(!st.empty()) {
        ans.PB(st.top());
        st.pop();
    }
    for(int i=n-p-1 ; i>=0 ; i--) cout << ans[i];
}