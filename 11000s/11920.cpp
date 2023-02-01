#include<bits/stdc++.h>
using namespace std;
#define PB(A) push_back(A)
#define ALL(A) (A).begin(), (A).end()

int n, k;
vector<int> v, w;
priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        v.PB(t);
    }
    for(int i=0 ; i<k ; i++) pq.push(v[i]);
    for(int i=0 ; i<n-k ; i++) {
        pq.push(v[i+k]);
        cout << pq.top() << ' ';
        pq.pop();
    }
    for(int i=0 ; i<k ; i++) {
        cout << pq.top() << ' ';
        pq.pop();
    }
}
