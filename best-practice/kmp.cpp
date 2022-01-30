#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> getPi(string p) {
	int psize = (int)p.size();
	int j = 0;
	vector<int> pi(psize, 0);
	for(int i=1 ; i<psize ; i++) {
		while(j>0 && p[i] != p[j]) j = pi[j-1];
		if(p[i] == p[j]) pi[i] = ++j;
	}
	return pi;
}

vector<int> kmp(string t, string p) {
	vector<int> ans;
	vector<int> pi = getPi(p);
	int tsize = (int)t.size();
	int psize = (int)p.size();
	for(int i=0, j=0 ; i<tsize ; i++) {
		while(j>0 && t[i] != p[j]) {
			j = pi[j-1];
		}	
		if(t[i] == p[j]) {
			if(j == psize-1) {
				ans.push_back(i-psize+1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string T, P;
	getline(cin, T);
	getline(cin, P);
	
	vector<int> matched = kmp(T, P);
	cout << matched.size() << '\n';
	for(int i=0 ; i<matched.size() ; i++) {
		cout << matched[i]+1 << ' ';
	}
}
