#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;

stack<int> gst, tst;
vector<int> gans, tans;

int main()
{
    int n, gcnt = 0, tcnt = 0;
    char s[2000001];
    scanf("%d", &n);
    scanf(" %s", s);
    for(int i=0 ; i<n*2 ; i++) {
        if(s[i] == 'g') {
            if(!tst.empty()) {
                tans.push_back(tst.top()); tst.pop();
                gans.push_back(++gcnt);
            }
            else {
                gst.push(++gcnt);
            }
        }
        else {
            if(!gst.empty()) {
                gans.push_back(gst.top()); gst.pop();
                tans.push_back(++tcnt);
            }
            else {
                tst.push(++tcnt);
            }
        }
    }
    
    if(gcnt != tcnt || !gst.empty() || !tst.empty()) {
        puts("NIE");
        return 0;
    }
    for(int i=0 ; i<n ; i++) {
        printf("%d %d\n", gans[i], tans[i]);
    }
}