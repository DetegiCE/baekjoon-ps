#include<cstdio>
#include<vector>
using namespace std;

typedef long long ll;

int N;
int flr;
ll tree[262147];
vector<ll> nums;

ll _max(ll a, ll b) {
    return a > b ? a : b;
}

void check(int idx, int st, int en) {
	if(idx*2 <= en) check(idx*2, st, en);
	if(st <= idx && idx <= en) nums.push_back(tree[idx]);
	if(idx*2+1 <= en) check(idx*2+1, st, en);
}

ll calc(int st, int en) {
	int startnum = (1<<(st-1));
	int endnum = (1<<en)-1;
	nums.clear();
	check(1, startnum, endnum);
	
	int numssz = nums.size();
	ll mx = 0;
	ll sums = 0;
	for(int i=0 ; i<numssz ; i++) {
		sums += nums[i];
		if(mx < sums) { 
			mx = sums;
		}
		if(sums < 0) {
			sums = 0;
		}
	}
	return mx;
}

int main()
{
	ll mx = -1e18;
    scanf("%d", &N);
    for(int i=1 ; i<=N ; i++) {
        scanf("%lld", &tree[i]);
        mx = _max(mx, tree[i]);
    }
    if(N == 1) {
        printf("%lld", tree[1]);
        return 0;
    }
    if(mx < 0) {
    	printf("%lld", mx);
		return 0;	
	}
    
    for(int i=1 ; i<=20 ; i++) {
        if((1<<i)-1 == N) {
            flr = i;
            break;
        }   
    }
    
    ll ans = 0;
    for(int i=1 ; i<=flr ; i++) {
        for(int j=i ; j<=flr ; j++) {
        	ll calcv = calc(i, j);
            ans = _max(ans, calcv);
        }
    }
    
    printf("%lld", ans);
}
