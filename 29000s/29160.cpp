#include <bits/stdc++.h>
using namespace std;

int n, k;
priority_queue<int> pq[12];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0 ; i<n ; i++) {
        int pi, wi;
        cin >> pi >> wi;
        pq[pi].push(wi);
    }
    for(int i=0 ; i<k ; i++) {
        for(int j=1 ; j<=11 ; j++) {
            if(!pq[j].empty()) {
                int pqt = pq[j].top();
                pq[j].pop();
                pq[j].push(max(0, pqt-1));
            }
        }
    }
    int sum = 0;
    for(int i=1 ; i<=11 ; i++) {
        if(!pq[i].empty()) {
            sum += pq[i].top();
        }
    }

    cout << sum;
}