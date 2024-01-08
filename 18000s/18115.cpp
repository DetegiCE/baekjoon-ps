#include<bits/stdc++.h>
using namespace std;

int n;
deque<int> dq;
vector<int> v;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    
    int cd = 1;
    for(int i=n-1 ; i>=0 ; i--) {
        if(v[i] == 1) {
            dq.push_back(cd);
        }
        if(v[i] == 2) {
            int t = dq.back();
            dq.pop_back();
            dq.push_back(cd);
            dq.push_back(t);
        }
        if(v[i] == 3) {
            dq.push_front(cd);
        }
        cd++;
    }
    
    for(int i=0 ; i<n ; i++) {
        cout << dq.back() << ' ';
        dq.pop_back();
    }
}
