#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 987654321
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;

int a[10003];
bool vis[10003];
int dst[10003];

void sol() {
    int n;
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        cin >> a[i];
        vis[i] = false;
        dst[i] = INF;
    }
    int cur = 1;
    dst[cur] = 0;
    while(cur != n) {
        if(dst[a[cur]] != INF) {
            cout << "0\n";
            return;
        }
        dst[a[cur]] = dst[cur] + 1;
        cur = a[cur];
    }
    cout << dst[n] << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
}