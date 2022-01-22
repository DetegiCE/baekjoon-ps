#include<cstdio>
#include<stack>
#include<utility>
using namespace std;

typedef pair<int,int> pii;

stack<pii> st;
long long count;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0 ; i<n ; i++) {
		int t;
		int same = 0;
		scanf("%d", &t);
		while(!st.empty() && st.top().first <= t) {
			if(st.top().first < t) {
				count += st.top().second;
			}
			else {
				same = st.top().second;
				count += st.top().second;
			}
			st.pop();
		}
		if(!st.empty()) count++;
		if(same) st.push({t, same+1});
		else st.push({t, 1});
		same = 0;
	}
	printf("%lld", count);
}
