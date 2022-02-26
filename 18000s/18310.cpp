#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int n;
ll sum;
vector<ll> homes;

ll minval;
int minpos;

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        ll t;
        scanf("%lld", &t);
        homes.push_back(t);
        sum += t;
    }
    sort(homes.begin(), homes.end());
    minpos = 0;
    minval = sum - homes[0] * n;

    ll curval = minval;
    for(int i=1 ; i<n ; i++) {
        curval += i * (homes[i] - homes[i-1]);
        curval -= (n-i) * (homes[i] - homes[i-1]);
        if(curval < minval) {
            minval = curval;
            minpos = i;
        }
    }
    printf("%d", homes[minpos]);
}