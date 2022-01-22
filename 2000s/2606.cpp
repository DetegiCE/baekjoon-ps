#include<cstdio>
#include<vector>
using namespace std;

int n, m;

typedef struct net {
	vector<int> link;
	bool visit;
} NET;

NET ne[101];
int count;

void virus(int p) {
	count++;
	ne[p].visit = true;
	for(int i=0 ; i<ne[p].link.size() ; i++) {
		int cur = ne[p].link[i];
		if(!ne[cur].visit){
			virus(cur);
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0 ; i<m ; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		ne[x].link.push_back(y);
		ne[y].link.push_back(x);
	}
	virus(1);
	printf("%d", count-1);
}
