#include<cstdio>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    ll arr[100001];
    ll acc[100001];
    ll sum = 0;
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf("%lld", &arr[i]);
        if(!i) acc[i] = arr[i];
        else acc[i] = arr[i] + acc[i-1];
    }
    for(int i=0 ; i<n ; i++) {
        sum += arr[i] * (acc[n-1] - acc[i]);
    }
    printf("%lld", sum);
}