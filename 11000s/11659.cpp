#include<cstdio>

int arr[100001];
int acc[100001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1 ; i<=n ; i++) {
		scanf("%d", &arr[i]);
		acc[i] = acc[i-1] + arr[i];
	}
	for(int i=0 ; i<m ; i++) {
		int s, t;
		scanf("%d %d", &s, &t);
		printf("%d\n", acc[t]-acc[s-1]);
	}
}
