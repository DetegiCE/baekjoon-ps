#include<bits/stdc++.h>
using namespace std;

string s;
int n, t;
int suff[500005], g[500005], tg[500005];
int lcp[500005], tl[500005];

bool comp(int a, int b) {
    if(g[a] == g[b]) return g[a+t] < g[b+t];
    else return g[a] < g[b];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> s;
    
    t = 1;
    n = s.length();
    for(int i=0 ; i<n ; i++) {
        suff[i] = i;
        g[i] = s[i]-97;
    }
    
    while(t <= n) {
        g[n] = -1;
        sort(suff, suff+n, comp);
        tg[suff[0]] = 0;
        
        for(int i=1 ; i<n ; i++) {
            if(comp(suff[i-1], suff[i])) tg[suff[i]] = tg[suff[i-1]] + 1;
            else tg[suff[i]] = tg[suff[i-1]];
        }
        
        for(int i=0 ; i<n ; i++) g[i] = tg[i];
        t *= 2;
    }
    
    for(int i=0 ; i<n ; i++) tl[suff[i]] = i;
    
    int len = 0;
    for(int i=0 ; i<n ; i++) {
        if(tl[i]) {
            int j = suff[tl[i]-1];
            while(s[j+len] == s[i+len]) len++;
            lcp[tl[i]] = len;
            
            if(len) len--;
        }
    }
    
    for(int i=0 ; i<n ; i++) cout << suff[i] + 1 << ' ';
    cout << "\nx ";
    for(int i=1 ; i<n ; i++) cout << lcp[i] << ' ';
}
