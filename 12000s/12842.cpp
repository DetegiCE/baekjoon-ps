#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a;
int t, x, r;

int main()
{
    int n, s, m;
    scanf("%d %d", &n, &s);
    scanf("%d", &m);
    for(int i=0 ; i<m ; i++) {
        int u;
        scanf("%d", &u);
        a.push_back(u);
    }    
    while(x != n-s) {
        for(int i=0 ; i<m ; i++) {
            if(t % a[i] == 0) {
                x++;
                r=i;
                if(x == n-s) break;
            }
        }
        t++;
    }
    printf("%d", r+1);
}