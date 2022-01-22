#include<cstdio>
#include<vector>
using namespace std;
#define MAX 1000000
#define MIN(A,B) (A>B?B:A)

int n;

typedef struct node {
	vector<int> edge;	
} NODE;

vector<NODE> N(MAX+1);
vector<bool> visit(MAX+1, false);
int dp[MAX+1][2]; //0: I'm early not adaptor, 1: I'm early adaptor
int visitCount;

void check(int cur) {
	visit[cur] = true;
	int siz = N[cur].edge.size();
	int count = 0;
	for(int i=0 ; i<siz ; i++) {
		if(!visit[N[cur].edge[i]]) {
			check(N[cur].edge[i]);
			count++;
			dp[cur][0] += dp[N[cur].edge[i]][1];
			dp[cur][1] += MIN(dp[N[cur].edge[i]][0], dp[N[cur].edge[i]][1]);
		}
	}
	dp[cur][1] += 1;
}

int main()
{
	scanf("%d", &n);
	for(int i=0 ; i<n-1 ; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		N[x].edge.push_back(y);
		N[y].edge.push_back(x);
	}
	check(1);
	printf("%d", MIN(dp[1][0], dp[1][1]));
}
