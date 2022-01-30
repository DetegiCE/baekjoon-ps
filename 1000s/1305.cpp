#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> getPi(string p) {
	int psize = p.size();
	vector<int> pi(psize, 0);
	
	int j = 0;
	for(int i=1 ; i<=psize ; i++) {
		while(j>0 && p[i] != p[j]) j = pi[j-1];
		if(p[i] == p[j]) pi[i] = ++j;
	}
	return pi;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int l;
	string s;
	cin >> l;
	cin >> s;
	
	vector<int> pi = getPi(s);
	printf("%d", l-pi[l-1]);
}
