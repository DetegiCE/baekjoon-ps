#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[500005];
int tmp[500005];
int cnt;

void merge(int p, int q, int r) {
    int i = p;
    int j = q+1;
    int t = 1;
    while(i <= q && j <= r) {
        if(a[i] <= a[j]) {
            tmp[t++] = a[i++];
        }
        else {
            tmp[t++] = a[j++];
        }
    }
    while(i <= q) {
        tmp[t++] = a[i++];
    }
    while(j <= r) {
        tmp[t++] = a[j++];
    }
    i = p;
    t = 1;
    while(i <= r) {
        cnt++;
        a[i++] = tmp[t++];
        if(cnt == k) {
            for(int e=0 ; e<n ; e++) {
                cout << a[e] << ' ';
            }
            exit(0);
        }
    }
}

void merge_sort(int p, int r) {
    if(p < r) {
        int q = (p+r)/2;
        merge_sort(p, q);
        merge_sort(q+1, r);
        merge(p, q, r);
    }
}

int main()
{
    cin >> n >> k;
    for(int i=0 ; i<n ; i++) cin >> a[i];
    
    merge_sort(0, n-1);
    cout << -1;
}
