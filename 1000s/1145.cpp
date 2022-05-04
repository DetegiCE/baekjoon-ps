#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define MIN(A,B) ((A)>(B)?(B):(A))

vector<int> v;
int mn;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main()
{
    for(int i=0 ; i<5 ; i++) {
        int t;
        scanf("%d", &t);
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    mn = 2147483647;
    do {
        int g = gcd(v[1], v[2]);
        int l = v[1] * v[2] / g;
        int n = gcd(v[0], l);
        int ans = v[0] * l / n;
        //printf("%d %d %d -> %d\n", v[0], v[1], v[2], ans);
        mn = MIN(mn, ans);
    } while(next_permutation(v.begin(), v.end()));
    printf("%d", mn);
}