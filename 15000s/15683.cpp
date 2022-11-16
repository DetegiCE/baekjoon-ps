#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

int n, m, ccnt, ans=99999, tmp;
int mapp[10][10];
int vopy[10][10];
vector<pip> v;
int cdir[10];

void right(int y, int x) {
    for(int i=x ; i<=m ; i++) {
        if(vopy[y][i] == 6) return;
        vopy[y][i] = 7;
    }
}

void down(int y, int x) {
    for(int i=y ; i<=n ; i++) {
        if(vopy[i][x] == 6) return;
        vopy[i][x] = 7;
    }
}

void left(int y, int x) {
    for(int i=x ; i>=1 ; i--) {
        if(vopy[y][i] == 6) return;
        vopy[y][i] = 7;
    }
}

void up(int y, int x) {
    for(int i=y ; i>=1 ; i--) {
        if(vopy[i][x] == 6) return;
        vopy[i][x] = 7;
    }
}

int draw() {
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            vopy[i][j] = mapp[i][j];
        }
    }
    for(int i=0 ; i<ccnt ; i++) {
        int cy = v[i].second.first;
        int cx = v[i].second.second;
        if((cdir[i] & 1) == 1) right(cy, cx);
        if((cdir[i] & 2) == 2) down(cy, cx);
        if((cdir[i] & 4) == 4) left(cy, cx);
        if((cdir[i] & 8) == 8) up(cy, cx);
    }
    int tcnt = 0;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            if(vopy[i][j] == 0) tcnt++;
        }
    }
    return tcnt;
}

void f(int cnum) {
    if(cnum == ccnt) {
        int tmp = draw();
        ans = min(ans, tmp);
        return;
    }
    
    int ctype = v[cnum].first;
    int cy = v[cnum].second.first;
    int cx = v[cnum].second.second;
    if(ctype == 1) {
        cdir[cnum] = 1;
        f(cnum+1);
        cdir[cnum] = 2;
        f(cnum+1);
        cdir[cnum] = 4;
        f(cnum+1);
        cdir[cnum] = 8;
        f(cnum+1);
    }
    else if(ctype == 2) {
        cdir[cnum] = 5;
        f(cnum+1);
        cdir[cnum] = 10;
        f(cnum+1);
    }
    else if(ctype == 3) {
        cdir[cnum] = 3;
        f(cnum+1);
        cdir[cnum] = 6;
        f(cnum+1);
        cdir[cnum] = 12;
        f(cnum+1);
        cdir[cnum] = 9;
        f(cnum+1);
    }
    else if(ctype == 4) {
        cdir[cnum] = 7;
        f(cnum+1);
        cdir[cnum] = 11;
        f(cnum+1);
        cdir[cnum] = 13;
        f(cnum+1);
        cdir[cnum] = 14;
        f(cnum+1);
    }
    else {
        cdir[cnum] = 15;
        f(cnum+1);
    }
}

int main()
{
	INP;
	
	cin >> n >> m;
	for(int i=1 ; i<=n ; i++) {
	    for(int j=1 ; j<=m ; j++) {
	        cin >> mapp[i][j];
	        if(1 <= mapp[i][j] && mapp[i][j] <= 5) {
	            v.PB(MP(mapp[i][j], MP(i, j)));
	            ccnt++;
	        }
	    }
	}
	f(0);
	cout << ans;
}