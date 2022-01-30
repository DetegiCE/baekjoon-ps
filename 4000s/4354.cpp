#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> getPi(string t) {
	int tsize = t.size();
	vector<int> pi(tsize, 0);
	
	int j = 0;
	for(int i=1 ; i<=tsize ; i++) {
		while(j>0 && t[i] != t[j]) j = pi[j-1];
		if(t[i] == t[j]) pi[i] = ++j;
	}
	return pi;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(true) {
		string t;
		cin >> t;
		if(t[0] == '.' && t.size() == 1) {
			break;
		}
		vector<int> pi = getPi(t);
		int tsize = t.size();
		if(tsize%(tsize-pi[tsize-1]) == 0) {
			printf("%d\n", tsize/(tsize-pi[tsize-1]));
		}
		else {
			printf("1\n");
		}
	}
}
