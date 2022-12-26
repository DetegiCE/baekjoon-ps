#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
#define MP(A,B) make_pair(A,B)

int n, m, h;
int lad[32][12];

bool check() {
    for(int j=1 ; j<=n ; j++) {
        int pos = j;
        for(int i=1 ; i<=h ; i++) {
            if(lad[i][pos]) pos++;
            else if(lad[i][pos-1]) pos--;
        }
        if(pos != j) return false;
    }
    return true;
}

void dfs(int dep, int cnt) {
    if(dep == cnt) {
        if(check()) {
            cout << dep;
            exit(0);
        }
        return;
    }
    for(int j=1 ; j<n ; j++) {
        for(int i=1 ; i<=h ; i++) {
            if(lad[i][j] || lad[i][j-1] || lad[i][j+1]) continue;
            lad[i][j] = 1;
            dfs(dep, cnt+1);
            lad[i][j] = 0;
            
            while(!lad[i][j-1] && !lad[i][j+1]) i++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> h;
    for(int i=0 ; i<m ; i++) {
        int a, b;
        cin >> a >> b;
        lad[a][b] = 1;
    }
    for(int i=0 ; i<=3 ; i++) {
        dfs(i, 0);
    }
    cout << -1;
}
