#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;

int n, k;
int tsiz;
int tree[270000];

void update(int* arr, int cur, int val) {
    if(cur == 0) return;
    arr[cur] += val;
    update(arr, cur/2, val);
}

int addup(int* arr, int lef, int rig) {
    // cout << lef << ' ' << rig << '\n';
    if(lef == rig) return arr[lef];
    int s = 0;
    if(lef % 2 == 1) s += arr[lef], lef++;
    if(rig % 2 == 0) s += arr[rig], rig--;
    return s + addup(arr, lef/2, rig/2);
}

void sol() {
    for(tsiz=1 ; tsiz<n ; tsiz*=2);
    for(int i=tsiz ; i<tsiz+n ; i++) {
        int t;
        cin >> t;
        if(t > 0) tree[i] = 1;
        if(t == 0) tree[i] = 0;
        if(t < 0) tree[i] = -1;
    }
    for(int i=tsiz+n ; i<tsiz*2 ; i++) tree[i] = 1;
    for(int i=tsiz-1 ; i>=1 ; i--) {
        tree[i] = tree[i*2] * tree[i*2+1];
    }
    // for(int i=1 ; i<=7 ; i++) cout << zer[i] << ' '; cout << '\n';
    for(int i=0 ; i<k ; i++) {
        char com;
        int j, v;
        cin >> com >> j >> v;
        if(com == 'C') {
            if(v == 0) tree[tsiz+j-1] = 0;
            else if(v > 0) tree[tsiz+j-1] = 1;
            else tree[tsiz+j-1] = -1;
            int cur = tsiz + j - 1;
            while(cur > 0) {
                cur /= 2;
                tree[cur] = tree[cur*2] * tree[cur * 2 + 1];
            }
        }
        else {
            int left = tsiz + j - 1;
            int right = tsiz + v - 1;
            int sum = 1;
            while(left <= right) {
                if(left == right) {
                    sum *= tree[left];
                    break;
                }
                if(left % 2 == 1) sum *= tree[left], left++;
                if(right % 2 == 0) sum *= tree[right], right--;
                left /= 2;
                right /= 2;
            }
            if(sum == 0) cout << '0';
            else if(sum < 0) cout << '-';
            else cout << '+';
        }
        // for(int k=0 ; k<n ; k++) cout << neg[k+tsiz] << ' ' ; cout << '\n';
    }
    cout << '\n';
}

int main()
{
    INP;
    
    while(cin >> n >> k) {
        sol();
    }
}