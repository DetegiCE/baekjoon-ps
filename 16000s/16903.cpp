#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
using namespace std;

map<int, int> mp;
bool flag;

struct Trie {
    Trie* go[2];
    int cnt = 0;

    Trie() {
        memset(go, 0, sizeof(go));
    }
    ~Trie() {
        for(int i=0 ; i<2 ; i++) {
            if(go[i]) delete go[i];
        }
    }
    void add(int t, int digit) {
        if(digit < 0) return;
        int nxt = t & (1 << digit);
        if(nxt != 0) nxt = 1;
        if(go[nxt] == NULL) {
            go[nxt] = new Trie;
        }
        cnt++;
        go[nxt]->add(t, digit-1);
    }
    void erase(int t, int digit) {
        if(digit < 0) return;
        int nxt = t & (1 << digit);
        if(digit == 0) {
            go[nxt] = NULL;
            cnt--;
            if(cnt > 0) flag = true;
            return;
        }
        if(nxt != 0) nxt = 1;
        go[nxt]->erase(t, digit-1);
        if(flag) return;
        else {
            go[nxt] = NULL;
            cnt--;
            if(cnt > 0) flag = true;
            return;
        }
    }
    int solve(int t, int digit) {
        if(digit < 0) return 0;
        int nxt = t & (1 << digit);

        int ret = 1 << digit;
        if(nxt != 0) {
            if(go[0] != NULL) return go[0]->solve(t, digit-1);
            else if(go[1] != NULL) return ret + go[1]->solve(t, digit-1);
            else return 0;
        }
        else {
            if(go[1] != NULL) return ret + go[1]->solve(t, digit-1);
            else if(go[0] != NULL) return go[0]->solve(t, digit-1);
            else return 0;
        }
    }
};

int main()
{
    int n;
    Trie *t = new Trie;
    t->add(0, 31);
    scanf("%d", &n);
    while(n--) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a == 1) {
            t->add(b, 31);
            mp[b]++;
        }
        if(a == 2) {
            if(--mp[b] == 0) {
                flag = false;
                t->erase(b, 31);
            }
        }
        if(a == 3) printf("%d\n", t->solve(b, 31) ^ b);
    }
}