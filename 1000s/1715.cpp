#include<bits/stdc++.h>
using namespace std;

int n, s;
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        pq.push(-t);
    }
    while(n > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+b);
        s -= a;
        s -= b;
        n--;
    }
    cout << s;
}