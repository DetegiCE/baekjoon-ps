#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

priority_queue<int> pqv;
priority_queue<int> pq;

string itos(int a) {
    string r = "";
    while(a > 0) {
        r += (char)((a%10)+'0');
        a /= 10;
    }
    reverse(r.begin(), r.end());
    return r;
}

int main()
{
    // INP;
    
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        pqv.push(t);
        if(pqv.size() > 4) {
            pqv.pop();
        }
    }
    
    string a = itos(pqv.top()); pqv.pop();
    string b = itos(pqv.top()); pqv.pop();
    string c = itos(pqv.top()); pqv.pop();
    string d;
    if(n >= 4) d = itos(pqv.top());
    
    pq.push(stoi(a+b));
    pq.push(stoi(a+c));
    pq.push(stoi(b+a));
    pq.push(stoi(b+c));
    pq.push(stoi(c+a));
    pq.push(stoi(c+b));
    if(n >= 4) {
        pq.push(stoi(d+a));
        pq.push(stoi(d+b));
        pq.push(stoi(d+c));
        pq.push(stoi(a+d));
        pq.push(stoi(b+d));
        pq.push(stoi(c+d));
    }
    
    for(int i=0 ; i<(n>=4?9:3) ; i++) pq.pop();
    cout << pq.top();
}