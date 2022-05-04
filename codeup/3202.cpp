#include<cstdio>

char tree[25000];

void gotree(int idx) {
    if(tree[idx] == 0) return;
    printf("%c", tree[idx]);
    gotree(idx*2);
    gotree(idx*2+1);
}

int main()
{
    scanf("%s", &tree[1]);
    gotree(1);
}