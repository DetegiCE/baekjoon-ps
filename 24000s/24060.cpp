#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0);cin.tie(0)

int n, k;
int a[500001];
int cnt;

void merge(int st, int md, int en) {
    int tmp[500001];
    int p1 = st, p2 = md + 1, tdx = 1;
    while(p1 <= md && p2 <= en) {
        if(a[p1] <= a[p2]) {
            tmp[tdx++] = a[p1++];
        }
        else {
            tmp[tdx++] = a[p2++];
        }
    }
    while(p1 <= md) {
        tmp[tdx++] = a[p1++];
    }
    while(p2 <= en) {
        tmp[tdx++] = a[p2++];
    }
    p1 = st;
    tdx = 1;
    while(p1 <= en) {
        a[p1++] = tmp[tdx++];
        if(++cnt == k) cout << tmp[tdx-1];
    }
}

void mergeSort(int st, int en) {
    int lef = st, rig = en;
    if(lef < rig) {
        int mid = (lef + rig) / 2;
        mergeSort(lef, mid);
        mergeSort(mid+1, rig);
        merge(lef, mid, rig);
    }
}

int main()
{
    INP;
    cin >> n >> k;
    for(int i=0 ; i<n ; i++) {
        cin >> a[i];
    }
    mergeSort(0, n-1);
    if(cnt < k) cout << -1;
}


