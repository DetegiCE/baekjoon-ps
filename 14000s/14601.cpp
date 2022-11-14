#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)

int n;
int x, y, cnt;
int mapp[130][130];

void f(int ys, int ye, int xs, int xe, int type) {
    if(ys == ye || xs == xe) return;
    int hy = (ys+ye)/2;
    int hx = (xs+xe)/2;
    if(type == 0) {
        int hpos = -1;
        if(y <= hy) {
            if(x <= hx) hpos = 1;
            else hpos = 2;
        }
        else {
            if(x <= hx) hpos = 3;
            else hpos = 4;
        }
        
        cnt++;
        mapp[hy][hx] = (hpos==1?mapp[hy][hx]:cnt);
        mapp[hy][hx+1] = (hpos==2?mapp[hy][hx+1]:cnt);
        mapp[hy+1][hx] = (hpos==3?mapp[hy+1][hx]:cnt);
        mapp[hy+1][hx+1] = (hpos==4?mapp[hy+1][hx+1]:cnt);
        
        f(ys, hy, xs, hx, hpos==1?0:4);
        f(ys, hy, hx+1, xe, hpos==2?0:3);
        f(hy+1, ye, xs, hx, hpos==3?0:2);
        f(hy+1, ye, hx+1, xe, hpos==4?0:1);
    }
    else {
        cnt++;
        mapp[hy][hx] = (type==1?mapp[hy][hx]:cnt);
        mapp[hy][hx+1] = (type==2?mapp[hy][hx+1]:cnt);
        mapp[hy+1][hx] = (type==3?mapp[hy+1][hx]:cnt);
        mapp[hy+1][hx+1] = (type==4?mapp[hy+1][hx+1]:cnt);
        
        f(ys, hy, xs, hx, type==1?1:4);
        f(ys, hy, hx+1, xe, type==2?2:3);
        f(hy+1, ye, xs, hx, type==3?3:2);
        f(hy+1, ye, hx+1, xe, type==4?4:1);
    }
}

int main()
{
    INP;
   
    cin >> n;
    cin >> y >> x;
    mapp[y][x] = -1;
    int hpos = -1;
    int nlen = (int)pow(2, n);
    if(y <= nlen/2) {
        if(x <= nlen/2) hpos = 1;
        else hpos = 2;
    }
    else {
        if(x <= nlen/2) hpos = 3;
        else hpos = 4;
    }
    
    cnt++;
    mapp[nlen/2][nlen/2] = (hpos==1?mapp[nlen/2][nlen/2]:cnt);
    mapp[nlen/2][nlen/2+1] = (hpos==2?mapp[nlen/2][nlen/2+1]:cnt);
    mapp[nlen/2+1][nlen/2] = (hpos==3?mapp[nlen/2+1][nlen/2]:cnt);
    mapp[nlen/2+1][nlen/2+1] = (hpos==4?mapp[nlen/2+1][nlen/2+1]:cnt);
    
    f(1, nlen/2, 1, nlen/2, hpos==1?0:4);
    f(1, nlen/2, nlen/2+1, nlen, hpos==2?0:3);
    f(nlen/2+1, nlen, 1, nlen/2, hpos==3?0:2);
    f(nlen/2+1, nlen, nlen/2+1, nlen, hpos==4?0:1);
    
    for(int j=nlen ; j>=1 ; j--) {
        for(int i=1 ; i<=nlen ; i++) {
            cout << mapp[i][j] << ' ';
        }
        cout << '\n';
    }
}