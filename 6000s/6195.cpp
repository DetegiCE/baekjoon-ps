#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, s;
priority_queue<ll> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        ll t;
        cin >> t;
        pq.push(-t);
    }
    while(n > 1) {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        pq.push(a+b);
        s -= a;
        s -= b;
        n--;
    }
    cout << s;
}