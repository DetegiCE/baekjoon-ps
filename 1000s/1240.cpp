#include<bits/stdc++.h>
using namespace std;

int n, m;
int dist[1001][1001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            dist[i][j] = 1e9;
            if(i == j) dist[i][i] = 0;
        }
    }
    for(int i=0 ; i<n-1 ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    for(int k=1 ; k<=n ; k++) {
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n ; j++) {
                if(dist[i][k] < 1e9 && dist[k][j] < 1e9 && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    while(m--) {
        int a, b;
        cin >> a >> b;
        cout << dist[a][b] << '\n';
    }
}
