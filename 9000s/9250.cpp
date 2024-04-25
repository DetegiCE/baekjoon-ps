#include <bits/stdc++.h>
using namespace std;

typedef struct trie {
    char data;
    bool isEnd;
    
    trie *prv, *nxt[26];
    trie(): isEnd{false} {
        for(int i=0 ; i<26 ; i++) {
            nxt[i] = NULL;
        }
    }
    
    ~trie() {
        for(int i=0 ; i<26 ; i++) {
            if(nxt[i] != NULL) delete nxt[i];
        }
    }
    
    void add(char* p) {
        if(*p == 0) {
            isEnd = true;
            return;
        }   
        
        if(nxt[*p - 'a'] == NULL)
            nxt[*p - 'a'] = new trie();
        nxt[*p - 'a']->add(p+1);
    }
} TRIE;

int n;
TRIE *root;
char str[10001];
queue<TRIE*> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    root = new TRIE();
    
    for(int i=0 ; i<n ; i++) {
        cin >> str;
        root->add(str);
    }
    root->prv = root;
    
    q.push(root);
    while(!q.empty()) {
        TRIE* cur = q.front();
        q.pop();
        
        for(int i=0 ; i<26 ; i++) {
            TRIE *next = cur->nxt[i];
            if(next == NULL) continue;
            
            if(cur == root) next->prv = root;
            else {
                TRIE* t = cur->prv;
                while(t != root && t->nxt[i] == NULL) {
                    t = t->prv;
                }
                if(t->nxt[i]) {
                    t = t->nxt[i];
                }
                next->prv = t;
            }
            
            if(next->prv->isEnd) next->isEnd = true;
            q.push(next);
        }
    }
    
    int q;
    cin >> q;
    while(q--) {
        cin >> str;
        
        TRIE* cur = root;
        bool chk = false;
        for(int i=0 ; str[i] != 0 ; i++) {
            int v = str[i] - 97;
            while(cur != root && cur->nxt[v] == NULL) {
                cur = cur->prv;
            }
            if(cur->nxt[v]) {
                cur = cur->nxt[v];
            }
            if(cur->isEnd) {
                chk = true;
                break;
            }
        }
        
        if(chk) cout << "YES\n";
        else cout << "NO\n";
    }
    
}
