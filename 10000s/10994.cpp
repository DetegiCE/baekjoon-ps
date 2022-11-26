#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 987654321
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;

int n;
int mapp[404][404];

void draw(int lev) {
    int c = (n-1)*2;
    for(int i=c-lev*2 ; i<=c+lev*2 ; i++) 
        mapp[c-lev*2][i] = mapp[c+lev*2][i] = mapp[i][c-lev*2] = mapp[i][c+lev*2] = 1;
}

int main()
{
    INP;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        draw(i);
    }
    for(int i=0 ; i<=(n-1)*4 ; i++) {
        for(int j=0 ; j<=(n-1)*4 ; j++) {
            if(mapp[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}