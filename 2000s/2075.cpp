#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

int n;
priority_queue<int> pq;

int main()
{
	INP;
	
	cin >> n;
	for(int i=0 ; i<n ; i++) {
	    for(int j=0 ; j<n ; j++) {
	        int t;
	        cin >> t;
	        pq.push(-t);
    	    if(pq.size() > n) {
    	        pq.pop();
    	    }
	    }
	}
	// for(int i=0 ; i<n-1 ; i++) pq.pop();
	cout << -pq.top();
}