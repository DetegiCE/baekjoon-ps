#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
typedef struct nums {
    char t30[10];
    int t10;
} NUMS;

NUMS nu[15001];

bool comp(NUMS a, NUMS b) {
    return a.t10 > b.t10;
}

void change(int a) {
    int tlen = strlen(nu[a].t30);
    for(int i=0 ; i<tlen ; i++) {
        nu[a].t10 *= 30;
        if(nu[a].t30[i] <= '9') nu[a].t10 += (nu[a].t30[i]-'0');
        else nu[a].t10 += (nu[a].t30[i]-'A'+10);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf(" %s", nu[i].t30);
        change(i);
    }
    sort(nu, nu+n, comp);
    for(int i=0 ; i<n ; i++) {
        printf("%s ", nu[i].t30);
    }
}