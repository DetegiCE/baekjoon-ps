#include<cstdio>
#include<vector>
using namespace std;

struct circle {
    int x;
    int y;
    int r;
    circle(int x, int y, int r):
    x(x), y(y), r(r) {};
};

vector<circle> v;
int cx, cy, n;

int dist(int x1, int yy1, int x2, int y2) {
    return (x1-x2)*(x1-x2)+(yy1-y2)*(yy1-y2);
}

int main()
{
    scanf("%d %d %d", &cx, &cy, &n);
    for(int i=0 ; i<n ; i++) {
        int x, y, r;
        scanf("%d %d %d", &x, &y, &r);
        v.push_back(circle(x, y, r));
    }
    for(int i=0 ; i<=3001 ; i++) {
        bool hasSame = false;
        int cnt = 0;
        for(int j=0 ; j<n ; j++) {
            int dst = dist(cx, cy, v[j].x, v[j].y);
            if(dst < (v[j].r+i)*(v[j].r+i)) {
                cnt++;
            }
        }
        if(cnt == 3) {
            if(i == 0) {
                printf("0");
                return 0;
            }
            printf("%d", i-1);
            return 0;
        }
    }
}