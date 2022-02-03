#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

typedef long long ll;
bool vb = false;

int n;
string s;
vector<int> pi;
vector<int> sav;

ll sum;

void getPi(string s) {
    int j = 0;

    for(int i=1 ; i<n ; i++) {
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) ++j;
        pi[i] = j;
    }
}

int backTrack(int cur) {
    if(pi[cur] == 0) return sav[cur] = cur+1;
    if(sav[cur] == -1) return sav[cur] = backTrack(pi[cur]-1);
    else return sav[cur];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> s;

    pi.assign(n, 0);
    getPi(s);
    sav.assign(n, -1);
    for(int i=n-1 ; i>=1 ; i--) {
        backTrack(i);
        sum += (ll)(i + 1 - sav[i]);
    }
    cout << sum;
}