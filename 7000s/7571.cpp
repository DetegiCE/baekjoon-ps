#include<cstdio>
#include<algorithm>
using namespace std;

int n, m;
int ax[100001];
int ay[100001];
int mx, my;
long long sum;

long long _abs(long long a) {
    if(a > 0) return a;
    else return -a;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0 ; i<m ; i++) {
        scanf("%d %d", &ax[i], &ay[i]);
    }
    sort(ax, ax+m);
    sort(ay, ay+m);
    mx = ax[m/2], my = ay[m/2];
    for(int i=0 ; i<m ; i++) {
        sum += _abs(mx-ax[i]);
        sum += _abs(my-ay[i]);
    }
    printf("%lld", sum);
}