#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

#define MAX(A,B) (A>B?A:B)

int n;
int d;

typedef struct rail {
	int st;
	int en;
} Rail;

vector<Rail> R;

priority_queue<int, vector<int>, greater<>> pq;

bool compare(Rail a, Rail b) {
	if(a.en == b.en) {
		return a.st < b.st;
	}
	return a.en < b.en;
}

int main()
{
	scanf("%d", &n);
	for(int i=0 ; i<n ; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if(x > y) {
			int t = x;
			x = y; 
			y = t;
		}
		R.push_back({x, y});
	}
	scanf("%d", &d);
	sort(R.begin(), R.end(), compare);
	
	int ans = 0;
	for(int i=0 ; i<n ; i++) {
		if(R[i].en - R[i].st > d) continue;
		pq.push(R[i].st);
		while(!pq.empty() && pq.top() < R[i].en - d) {
			pq.pop();
		}
		ans = MAX(ans, pq.size());
	}
	printf("%d", ans);
}
