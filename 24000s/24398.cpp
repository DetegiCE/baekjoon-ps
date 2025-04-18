#include <bits/stdc++.h>
using namespace std;

int n, q, k;
vector<int> a;

int partition(int p, int r) {
    int x = a[r];
    int i = p-1;
    for(int j=p ; j<r ; j++) {
        if(a[j] <= x) {
            i++;
            k--;
            swap(a[i], a[j]);
            if(!k) {
                cout << min(a[i], a[j]) << ' ' << max(a[i], a[j]);
                exit(0);
            }
        }
    }
    if(i+1 != r) {
        k--;
        swap(a[i+1], a[r]);
        if(!k) {
            cout << min(a[i+1], a[r]) << ' ' << max(a[i+1], a[r]);
            exit(0);
        }
    }
    return i+1;
}

int select(int p, int r, int q) {
    if(p == r) return a[p];
    int t = partition(p, r);
    int k = t - p + 1;
    if(q < k) return select(p, t-1, q);
    else if(q == k) return a[t];
    else return select(t+1, r, q-k);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q >> k;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    select(0, n-1, q);
    cout << -1;
}