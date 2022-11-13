#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)
typedef long long ll;

int main()
{
    INP;
    
    int n;
    int cur = 1;
    stack<int> st;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        while(!st.empty() && st.top() == cur) {
            st.pop();
            cur++;
        }
        if(t == cur) {
            cur++;
        }
        else {
            st.push(t);
        }
        
    }
    while(!st.empty() && st.top() == cur) {
        st.pop();
        cur++;
    }
    if(st.empty()) cout << "Nice";
    else cout << "Sad";
}