#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

char s[1000001], t[100001];
int slen, tlen;
vector<int> pos[27];

int cnt = 1;
int curpos = -1;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> s;
    cin >> t;

    slen = strlen(s);
    tlen = strlen(t);

    for(int i=0 ; i<tlen ; i++) {
        pos[t[i]-'a'].push_back(i);
    }

    for(int i=0 ; i<slen ; i++) {
        // lets find s[i]
        if(pos[s[i]-'a'].size() == 0) {
            puts("-1");
            return 0;
        }
        vector<int>::iterator nxtpos = upper_bound(pos[s[i]-'a'].begin(), pos[s[i]-'a'].end(), curpos);
        if(nxtpos == pos[s[i]-'a'].end()) {
            cnt++;
            curpos = -1;
            curpos = *upper_bound(pos[s[i]-'a'].begin(), pos[s[i]-'a'].end(), curpos);
        }
        else {
            curpos = *nxtpos;
        }
    }
    printf("%d", cnt);
}