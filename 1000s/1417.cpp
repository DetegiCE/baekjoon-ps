#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

int n, d, c;
priority_queue<int> pq;

int main()
{
	INP;
	
	cin >> n;
	cin >> d;
	if(n == 1) {
	    cout << 0;
	    return 0;
	}
	for(int i=0 ; i<n-1 ; i++) {
	    int t;
	    cin >> t;
	    pq.push(t);
	}
	while(d <= pq.top()) {
	    d++;
	    c++;
	    int pt = pq.top();
	    pq.pop();
	    pt--;
	    pq.push(pt);
	}
	cout << c;
}