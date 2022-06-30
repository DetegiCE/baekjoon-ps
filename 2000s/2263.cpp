#include<cstdio>

int n;
int inOrder[100001];
int postOrder[100001];

void f(int in_st, int in_en, int post_st, int post_en) {
    if(in_st > in_en || post_st > post_en) return;
    int par = postOrder[post_en];
    printf("%d ", par);

    if(in_st == in_en) return;

    int parpos = -1;
    for(int i=in_st ; i<=in_en ; i++) {
        if(inOrder[i] == par) {
            parpos = i;
            break;
        }
    }

    f(in_st, parpos-1, post_st, post_st+parpos-in_st-1);
    f(parpos+1, in_en, post_st+parpos-in_st, post_en-1);
}

int main()
{
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++) {
        scanf("%d", &inOrder[i]);
    }
    for(int i=1 ; i<=n ; i++) {
        scanf("%d", &postOrder[i]);
    }
    f(1, n, 1, n);
}