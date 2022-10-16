#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0);cin.tie(0)

priority_queue<int> pq;

int main()
{
    INP;
    
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int a;
        cin >> a;
        if(a == 0) {
            if(pq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            for(int j=0 ; j<a ; j++) {
                int t;
                cin >> t;
                pq.push(t);
            }
        }
    }
}