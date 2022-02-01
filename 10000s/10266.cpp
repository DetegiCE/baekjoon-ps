#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int n;
string a, b;

vector<int> getPi() {
    int bsize = b.size();
    vector<int> pi(bsize, 0);

    int j = 0;
    for(int i=1 ; i<bsize ; i++) {
        while(j>0 && b[i] != b[j]) j = pi[j-1];
        if(b[i] == b[j]) pi[i] = ++j;
    }
    return pi;
}

bool kmp() {
    vector<int> pi = getPi();
    int asize = a.size();
    int bsize = b.size();
    for(int i=0, j=0 ; i<asize ; i++) {
        while(j>0 && a[i] != b[j]) j = pi[j-1];
        if(a[i] == b[j]) {
            if(j == bsize-1) return true;
            else j++;
        }
    }
    return false;
}

int main()
{
    for(int i=0 ; i<360000 ; i++) {
        a += '0';
        b += '0';
    }

    int t;
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &t);
        a[t] = '1';
    }
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &t);
        b[t] = '1';
    }

    a += a;
    if(kmp()) printf("possible");
    else printf("impossible");
}