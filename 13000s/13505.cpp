#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX(A,B) (A>B?A:B)

struct Trie {
	Trie* go[2];
	bool end = false;
	bool exist = false;
	
	Trie() {
		memset(go, 0, sizeof(go));
	}
	~Trie() {
		for(int i=0 ; i<2 ; i++) {
			if(go[i]) delete go[i];
		}
	}
	void add(int t, int digit) {
		if(digit < 0) {
			end = true;
			return;
		}
		int next = t & (1 << digit);
		
		if(next != 0) next = 1;
		
		if(!go[next]) {
			go[next] = new Trie;
		}
		exist = true;
		go[next]->add(t, digit-1);
	}
	int solve(int t, int digit) {
		if(digit < 0) return 0;
		int next = t & (1 << digit);
		
		if(next == 0) next = 1;
		else next = 0;
		
		int ret = 0;
		if(!go[next]) {
			next = !next;
		}
		else {
			ret = 1 << digit;
		}
		
		return ret + go[next]->solve(t, digit-1);
	}
};

int N;
vector<int> num;

int main()
{
	Trie *t = new Trie;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++) {
		int tmp;
		scanf("%d", &tmp);
		t->add(tmp, 31);
		num.push_back(tmp);
	}
	int ans = 0;
	for(int i=0 ; i<N ; i++) {
		ans = MAX(ans, t->solve(num[i], 31));
	}
	printf("%d", ans);
}
