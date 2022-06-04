#include<cstdio>
#include<map>
using namespace std;

struct sets {
    int cnt, a;
};
map<int, sets> mp;

int main()
{
    int n, c = 0;
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++) {
        c *= 10;
        c += 1;
        c %= n;
        if(c == 0) {
            for(int j=0 ; j<i ; j++) printf("1");
            return 0;
        }
        if(mp[c].cnt == 0) {
            mp[c].cnt = 1;
            mp[c].a = i;
        }
        else {
            for(int j=0 ; j<i-mp[c].a ; j++) printf("1");
            for(int j=0 ; j<mp[c].a ; j++) printf("0");
            return 0;
        }
    }
}