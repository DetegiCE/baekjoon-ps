#include<cstdio>

int n, cnt;
bool sieve[7400004];

int main()
{
    scanf("%d", &n);

    for(int i=2 ; i<=7400000 ; i++) {
        if(!sieve[i]) {
            cnt++;
            if(cnt == n) {
                printf("%d", i);
                return 0;
            }
            for(int j=i*2 ; j<=7400000 ; j+=i) sieve[j] = true;
        }
    }
}

