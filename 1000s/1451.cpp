#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
ll oc[51][51];
ll ac[51][51];
ll mx;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> m;
	for(int i=1 ; i<=n ; i++) {
	    cin.ignore();
	    string t;
	    cin >> t;
	    for(int j=1 ; j<=m ; j++) {
	        oc[i][j] = t[j-1] - 48;
	    }
	}
	for(int i=1 ; i<=n ; i++) {
	    for(int j=1 ; j<=m ; j++) {
	        ac[i][j] = ac[i-1][j] + ac[i][j-1] - ac[i-1][j-1] + oc[i][j];
	    }
	}
	
	
	for(int i=1 ; i<=n ; i++) {
	    for(int j=i+1 ; j<=n ; j++) {
	        for(int k=j+1 ; k<=n ; k++) {
	            ll is = ac[i][m];
	            ll js = ac[j][m] - ac[i][m];
	            ll ks = ac[k][m] - ac[j][m];
	            mx = max(mx, is*js*ks);
	        }
	    }
	}
	
	for(int i=1 ; i<=m ; i++) {
	    for(int j=i+1 ; j<=m ; j++) {
	        for(int k=j+1 ; k<=m ; k++) {
	            ll is = ac[n][i];
	            ll js = ac[n][j] - ac[n][i];
	            ll ks = ac[n][k] - ac[n][j];
	            mx = max(mx, is*js*ks);
	        }
	    }
	}
	
	// |-
	for(int i=1 ; i<m ; i++) {
	    for(int j=1 ; j<n ; j++) {
	        ll is = ac[n][i];
	        ll js = ac[j][m] - ac[j][i];
	        ll ks = ac[n][m] - is - js;
	        mx = max(mx, is*js*ks);
	    }
	}
	
	// -|
	for(int i=2 ; i<=m ; i++) {
	    for(int j=1 ; j<n ; j++) {
	        ll is = ac[n][m] - ac[n][i-1];
	        ll js = ac[j][i-1];
	        ll ks = ac[n][m] - is - js;
	        mx = max(mx, is*js*ks);
	    }
	}
	
	// ㅗ
	for(int i=2 ; i<=n ; i++) {
	    for(int j=1 ; j<m ; j++) {
	        ll is = ac[n][m] - ac[i-1][m];
	        ll js = ac[i-1][j];
	        ll ks = ac[n][m] - is - js;
	        mx = max(mx, is*js*ks);
	    }
	}
	
	// ㅜ
	for(int i=1 ; i<n ; i++) {
	    for(int j=1 ; j<m ; j++) {
	        ll is = ac[i][m];
	        ll js = ac[n][j] - ac[i][j];
	        ll ks = ac[n][m] - is - js;
	        mx = max(mx, is*js*ks);
	    }
	}
	
	cout << mx;
}
