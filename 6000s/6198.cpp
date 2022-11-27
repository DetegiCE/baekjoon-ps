#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;
typedef pair<int,int> pii;

ll n, h[80008], s;
stack<ll> st;

int main()
{
    INP;
    
    cin >> n;
    for(int i=0 ; i<n ; i++) cin >> h[i];
    for(int i=0 ; i<n ; i++) {
        if(st.empty()) {
            st.push(h[i]);
        }
        else {
            while(!st.empty() && st.top() <= h[i]) st.pop();
            s += st.size();
            st.push(h[i]);
        }
    }
    cout << s;
}