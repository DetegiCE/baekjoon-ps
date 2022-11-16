#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

int n, m, mapp[303][303], vopy[303][303];
int bcnt = 0;

void makefill() {
    int cnt[303][303] = {0};
	for(int i=1 ; i<=n ; i++) {
		for(int j=1 ; j<=m ; j++) {
		    if(mapp[i-1][j] == 0) cnt[i][j]++;
		    if(mapp[i+1][j] == 0) cnt[i][j]++;
		    if(mapp[i][j-1] == 0) cnt[i][j]++;
		    if(mapp[i][j+1] == 0) cnt[i][j]++;
		}
	}
	for(int i=1 ; i<=n ; i++) {
		for(int j=1 ; j<=m ; j++) {
		    mapp[i][j] -= cnt[i][j];
		    if(mapp[i][j] < 0) mapp[i][j] = 0;
		}
	}
}

bool countgroups() {
	int cnt = 0;
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<m ; j++) {
			vopy[i][j] = mapp[i][j];
		}
	}
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<m ; j++) {
			if(vopy[i][j] == 0) continue;
			cnt++;
			queue<pii> q;
			q.push(MP(i,j));
			while(!q.empty()) {
				pii now = q.front();
				q.pop();
				
				int x = now.first, y = now.second;
				if(vopy[x][y] == 0) continue;
				vopy[x][y] = 0;
				if(x-1 >= 0) q.push(MP(x-1,y));
				if(x+1 < n) q.push(MP(x+1,y));
				if(y-1 >= 0) q.push(MP(x,y-1));
				if(y+1 < m) q.push(MP(x,y+1));
			}
		}
	}
	if(cnt == 0) bcnt = 1;
	return cnt > 1;
}

int main()
{
	INP;
	
	cin >> n >> m;
	for(int i=0 ; i<n ; i++) {
	    for(int j=0 ; j<m ; j++) {
	        cin >> mapp[i][j];
	    }
	}
    for(int i=0 ; i<=100000 ; i++) {
        bcnt = 0;
		if(countgroups()) {
			cout << i;
			return 0;
		}
		if(bcnt == 1) {
		    cout << 0;
		    return 0;
		}
        makefill();
    }
	cout << 0;
}