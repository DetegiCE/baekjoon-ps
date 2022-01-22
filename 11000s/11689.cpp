#include<cstdio>
#include<vector>
using namespace std;

long long n;
long long value;

int main()
{
	scanf("%lld", &n);
	value = n;
	for(long long i = 2; i * i <= n ; i++) {
		if(n % i == 0) {
			while(n % i == 0) {
				n /= i;
			}
			value /= i;
			value *= (i-1);
		}
	}
	if(n != 1) {
		value /= n;
		value *= (n-1);
	}
	printf("%lld", value);
}
