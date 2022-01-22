#include<cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	for(int i=0 ; i<t ; i++) {
		int a, b, o;
		scanf("%d %d", &a, &b);
		o = a;
		for(int j=0 ; j<b-1 ; j++) {
			a *= o;
			a %= 10;
		}
		printf("%d\n", a % 10 == 0 ? 10 : a % 10);
	}
}
