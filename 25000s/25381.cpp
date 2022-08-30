#include<bits/stdc++.h>
using namespace std;

char s[300001];
bool used[300001];

int cnt;

int main()
{
    scanf("%s", s);
    int len = strlen(s);
    
    int acnt=0, bcnt=0, ccnt=0;
    for(int i=0 ; i<len ; i++) {
        if(s[i] == 'A') acnt++;
        if(s[i] == 'B' && acnt) acnt--, cnt++;
        if(s[i] == 'B') bcnt++;
    }
    for(int i=len-1 ; i>=0 ; i--) {
        if(s[i] == 'C') ccnt++;
        if(s[i] == 'B' && ccnt) ccnt--, cnt++;
    }
    printf("%d", min(bcnt, cnt));
}