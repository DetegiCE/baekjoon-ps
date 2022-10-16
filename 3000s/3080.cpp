#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;

struct Trie {
    bool isEnd;
    struct Trie* next[26];
    
    Trie(): isEnd(false) {
        for(int i=0 ; i<26 ; i++) next[i] = NULL;
    }
    
    ~Trie() {
        for(int i=0 ; i<26 ; i++) if(next[i]) delete next[i];
    }
    
    void insert(const char* str, int len) {
        if((*str) == 0 || len == -1) {
            isEnd = true;
            return;
        }
        int key = (*str) - 'A';
        if(next[key] == NULL) {
            next[key] = new Trie();
        }
        // printf("[%s: %d]\n", str, child);
        next[key] -> insert(str+1, len-1);
    }
    
    ll calc() {
        ll ans = 1, cnt = 0;
        for(int i=0 ; i<26 ; i++) {
            if(next[i]) {
                ans *= next[i] -> calc();
                ans %= MOD;
                cnt++;
            }
        }
        if(isEnd) cnt++;
        for(ll i=1 ; i<=cnt ; i++) {
            ans *= i;
            ans %= MOD;
        }
        return ans % MOD;
    }
};

string names[3001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    Trie* root = new Trie();
    for(int i=0 ; i<n ; i++) {
        cin >> names[i];
    }
    sort(names, names+n);
    
    int beflen = 0, aftlen = 0;
    
    for(int i=0 ; i<n-1 ; i++) {
        for(int j=0 ; j<names[i].length() ; j++) {
            if(names[i][j] != names[i+1][j]) break;
            aftlen = j;
        }
        root -> insert(names[i].c_str(), max(beflen, aftlen) + 1);
        beflen = aftlen;
    }
    root -> insert(names[n-1].c_str(), beflen + 1);
    cout << ((root -> calc()) % MOD);
}