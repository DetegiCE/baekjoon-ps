#include<cstdio>
#include<cstring>

int nums[27];
char word[103];
int n, cnt;

int word2num() {
    int ret = 0;
    for(int i=0 ; word[i]!=0 ; i++) {
        ret |= (1 << (word[i]-'a'));
    }
    return ret;
}

void sol(int pos, int bit) {
    if(pos == n) {
        if(bit == (1<<26)-1) cnt++;
        return;
    }
    sol(pos+1, bit);
    sol(pos+1, bit | nums[pos]);
}

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf(" %s", word);
        nums[i] = word2num();
    }
    sol(0,0);
    printf("%d", cnt);
}