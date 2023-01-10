#include<bits/stdc++.h>
using namespace std;

char ans[12];
int a, b, c;
void f(int pos, int len, int star, int bang) {
    if(pos == len) {
        cout << ans << '\n';
        return;
    }
    if(star < b) {
        ans[pos] = '*';
        f(pos+1, len, star+1, 0);
    }
    if(bang < c) {
        ans[pos] = '!';
        f(pos+1, len, 0, bang+1);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int cnt = 0;
    while(true) {
        cin >> a >> b >> c;
        if(a == 0) break;
        cout << "Sequence set " << ++cnt << '\n';
        f(0, a, 0, 0);
        for(int i=0 ; i<11 ; i++) ans[i] = '\0';
    }
}
