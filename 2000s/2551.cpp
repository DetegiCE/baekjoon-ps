#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, mn1, mn2, mni1, mni2;
ll cnt[10001];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	for(int i=0 ; i<n ; i++) {
	    int t;
	    cin >> t;
	    cnt[t]++;
	}
	
	for(int i=1 ; i<=10000 ; i++) {
	    ll d1=0, d2=0;
	    for(int j=1 ; j<=10000 ; j++) {
	        if(cnt[j] > 0) {
	            d1 += abs(j-i) * cnt[j];
	            d2 += (j-i) * (j-i) * cnt[j];
	        }
	    }
	    if(i==1) {
	        mn1 = d1;
	        mn2 = d2;
	        mni1 = mni2 = 1;
	    }
	    if(d1 < mn1) {
	        mn1 = d1;
	        mni1 = i;
	    }
	    if(d2 < mn2) {
	        mn2 = d2;
	        mni2 = i;
	    }
	}
	
	cout << mni1 << ' ' << mni2;
}
