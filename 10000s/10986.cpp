#include<cstdio>

typedef long long ll;

int n, m;
int arr[1000001], acc[1000001];
ll cnt[1001];
ll sum;

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &arr[i]);
        arr[i] %= m;
        if(i) acc[i] = arr[i] + acc[i-1];
        else acc[i] = arr[i];
        cnt[acc[i]%m]++;
    }
    sum = cnt[0];
    for(int i=0 ; i<m ; i++) {
        sum += cnt[i] * (cnt[i] - 1) / 2;
    }
    printf("%lld", sum);
}