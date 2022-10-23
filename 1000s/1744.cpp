#include<bits/stdc++.h>
using namespace std;

int m;
int p[51], n[51], pcnt, ncnt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m;
    for(int i=0 ; i<m ; i++) {
        int t;
        cin >> t;
        if(t > 0) p[pcnt++] = t;
        else n[ncnt++] = t;
    }    
    sort(p, p+pcnt, greater<int>());
    sort(n, n+ncnt);
    
    int s=0;
    for(int i=0 ; i<pcnt ; i++) {
        if(i+1 < pcnt) {
            if(p[i] + p[i+1] > p[i] * p[i+1]) s += p[i] + p[i+1];
            else s += p[i] * p[i+1];
            i++;
        }
        else {
            s += p[i];
        }
    }
    for(int i=0 ; i<ncnt ; i++) {
        if(i+1 < ncnt) {
            s += n[i] * n[i+1];
            i++;
        }
        else {
            s += n[i];
        }
    }
    cout << s;
}