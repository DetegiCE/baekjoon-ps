#include<bits/stdc++.h>
using namespace std;

char s[1001];
int cnt[27];

int main()
{
    scanf("%s", s);
    for(int i=0 ; s[i]!=0 ; i++) {
        cnt[s[i]-'a']++;
    }
    int ocnt=0, ecnt=0;
    for(int i=0 ; i<26 ; i++) {
        if(cnt[i] % 2) ocnt++;
        else ecnt++;
    }
    if(ocnt == 0) puts("0");
    else printf("%d", ocnt-1);
}