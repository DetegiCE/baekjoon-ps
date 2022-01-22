#include<cstdio>
#define MOD 1000000007

long long fact[4000001];

long long pow(long long a, long long b) {
	if(b == 0) return 1;
	if(b % 2 == 0) return pow((a*a)%MOD, b/2) % MOD;
	else return (a * pow(a, b-1) % MOD) % MOD;
}

int main()
{
	int m;
	scanf("%d", &m);
	fact[0] = fact[1] = 1;
	for(int i=2 ; i<=4000000 ; i++) fact[i] = (fact[i-1] * i) % MOD;
	
	for(int i=0 ; i<m ; i++) {
		int n, k;
		scanf("%d %d", &n, &k);
		long long up = fact[n];
		long long down = (fact[k] * fact[n-k]) % MOD;
		down = pow(down, MOD-2) % MOD;
		printf("%lld\n", (up * down) % MOD);
	}
}
