#include<cstdio>
#include<cstring>

#define MIN(A,B) (A>B?B:A)

char st[21];
int slen;
int n[21], ans[21];

int main()
{
    scanf("%s", st);
    slen = strlen(st);
    for(int i=0 ; i<slen ; i++) n[i] = st[slen-i-1]-'0';

    int cur = 0;
    int sum = 0;
    while(sum == 0 || n[cur] == 9) {
        sum += n[cur];
        cur++;
    }
    sum--;
    
    for(int i=0 ; i<cur ; i++) {
        ans[i] = MIN(sum, 9);
        sum -= ans[i];
    }
    ans[cur] = n[cur] + 1;
    for(int i=cur+1 ; i<slen ; i++) ans[i] = n[i];

    if(ans[slen] != 0) printf("%d", ans[slen]);
    for(int i=slen-1 ; i>=0 ; i--) {
        printf("%d", ans[i]);
    }

}

// 0 0 2
// sum 0
// cur 3
// 1 0 0 1