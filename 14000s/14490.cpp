#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long ll;

int gcd(int a, int b) {
    return b ? gcd(b, a%b): a;
}

int main()
{
    int n, m;
    scanf("%d:%d", &n, &m);
    int g = gcd(n, m);
    printf("%d:%d", n/g, m/g);
}
