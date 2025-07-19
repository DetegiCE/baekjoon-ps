#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int p;
    cin >> p;
    for(int i=1 ; i<=p ; i++) {
        int n, m;
        cin >> n >> m;
        cout << n << ' ';
        int prev = 1;
        int cur = 1;
        int cnt = 0;
        do {
            cnt++;
            int nprev = cur;
            int ncur = (prev + cur) % m;
            prev = nprev;
            cur = ncur;
        } while(prev != 1 || cur != 1);
        cout << cnt << '\n';
    }
}