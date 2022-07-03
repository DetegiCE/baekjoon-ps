#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX(A,B) (A>B?A:B)

struct vill {
    int a, p;
};

int n, k;
vector<vill> v;

int main()
{
    scanf("%d %d", &n, &k);
    v.resize(n+1);
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &v[i].a);
    }
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &v[i].p);
    }

    int mxans = 0;
    for(int i=0 ; i<(1<<n) ; i++) {
        int t = i, cnt = 0;
        vector<int> atk;
        while(t >= 1) {
            if(t%2==1) {
                // printf("C%d\n", cnt); 
                atk.push_back(v[cnt].a);
            }
            cnt++;
            t/=2;
        }
        sort(atk.begin(), atk.end());
        int sum = 0, tsum = 0;
        for(int j=0 ; j<atk.size() ; j++) {
            tsum += atk[j];
            sum += tsum;
        }

        t = i;
        cnt = 0;
        int tans = 0;
        if(sum <= k) {
            while(t >= 1) {
                if(t%2==1) {
                    tans += v[cnt].p;
                }
                t/=2;
                cnt++;
            }
        }
        mxans = MAX(mxans, tans);
        // printf("%d %d %d\n", i, tans, sum);
    }
    printf("%d", mxans);
}