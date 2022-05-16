#include<cstdio>
#include<algorithm>
using namespace std;

int n, cnt = 0;
int ar[2000002];

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &ar[i]);
    }
    sort(ar, ar+n);
    for(int i=0 ; i<(n+1)/2 ; i++) {
        while(ar[i] > 1) {
            cnt++;
            ar[i] /= 2;
        }
    }
    printf("%d", cnt + 1);
}