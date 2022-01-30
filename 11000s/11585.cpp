#include<iostream>
#include<string>
#include<vector>
using namespace std;

int gcd(int a, int b) {
	return b?gcd(b, a%b):a;
}

vector<int> getPi(string p) {
	int psize = p.size();
	vector<int> pi(psize, 0);
	
	int j = 0;
	for(int i=1 ; i<psize ; i++) {
		while(j>0 && p[i] != p[j]) j = pi[j-1];
		if(p[i] == p[j]) pi[i] = ++j;
	}
	return pi;
}

int kmp(string t, string p) {
	vector<int> pi = getPi(p);
	
	int tsize = t.size();
	int psize = p.size();
	int j = 0;
	int cnt = 0;
	for(int i=0 ; i<tsize ; i++) {
		while(j>0 && t[i] != p[j]) j = pi[j-1];
		if(t[i] == p[j]) {
			if(j == psize-1) {
				cnt++;
				j = pi[j];
			}
			else j++;
		}
	}
	return cnt;
}

char ct[2000001], cp[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	scanf("%d", &n);
	for(int i=0 ; i<n ; i++) {
		scanf(" %c", &cp[i]);
	}
	for(int i=0 ; i<n ; i++) {
		scanf(" %c", &ct[i]);
		if(i<n-1) ct[n+i] = ct[i];
	}
	
	string p(cp), t(ct);
	
	int cnt = kmp(t, p);
	int g = gcd(cnt, n);
	cout << cnt/g << '/' << n/g;
}
