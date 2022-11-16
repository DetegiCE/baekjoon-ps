#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

int n, k;
int wordnum[51];
string words[51];

bool vis[26];
int vnum;
int ans;

void go(int cur, int cnt) {
    // cout << cur << ' ' << cnt << ' ' << vnum << '\n';
    if(cnt == k) {
        int tcnt = 0;
        for(int i=0 ; i<n ; i++) {
            // cout << "    " << wordnum[i] << ' ' << (wordnum[i] & vnum) << '\n';
            if((wordnum[i] & vnum) == wordnum[i]) {
                tcnt++;
            }
        }
        ans = max(ans, tcnt);
        return;
    }
    for(int i=cur ; i<26 ; i++) {
        if(!vis[i]) {
            vis[i] = true;
            vnum += (1<<i);
            go(i+1, cnt+1);
            vnum -= (1<<i);
            vis[i] = false;
        }
    }
}

int main()
{
	INP;
	
	cin >> n >> k;
	string tmp;
	for(int i=0 ; i<n ; i++) {
	    getline(cin, tmp);
	    cin >> tmp;
	    for(int j=0 ; j<tmp.length() ; j++) {
	        wordnum[i] |= (1<<(tmp[j] - 'a'));
	    }
	   // cout << wordnum[i] << '\n';
	}
	
	if(k < 5) {
	    cout << 0;
	    return 0;
	}
	else if(k == 26) {
	    cout << n;
	    return 0;
	}
	
	// a c n i t
	vis[0] = true;
	vis[2] = true;
	vis['n'-'a'] = true;
	vis['i'-'a'] = true;
	vis['t'-'a'] = true;
	vnum = 1 + 4 + (1<<('n'-'a')) + (1<<('i'-'a')) + (1<<('t'-'a'));
	
	go(1,5);
	cout << ans;
}