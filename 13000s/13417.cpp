#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)
#define PF(A) push_front(A)
typedef long long ll;
    
int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        deque<char> dq;
        scanf("%d", &n);
        for(int i=0 ; i<n ; i++) {
            char c;
            scanf(" %c", &c);
            if(i == 0) dq.PB(c);
            else {
                if(c > dq.front()) dq.PB(c);
                else dq.PF(c);
            }
        }
        for(int i=0 ; i<n ; i++) {
            printf("%c", dq.front());
            dq.pop_front();
        }
        puts("");
    }
}