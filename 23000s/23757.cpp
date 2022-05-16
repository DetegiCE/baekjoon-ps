#include<cstdio>
#include<queue>
using namespace std;

priority_queue<int> pq;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0 ; i<n ; i++) {
        int t;
        scanf("%d", &t);
        pq.push(t);
    }
    for(int i=0 ; i<m ; i++) {
        if(pq.empty()) {
            puts("0");
            return 0;
        }
        int t, pt = pq.top();
        scanf("%d", &t);
        if(t > pt) {
            puts("0");
            return 0;
        }
        else if(t == pt) {
            pq.pop();
        }
        else {
            pq.pop();
            pq.push(pt-t);
        }
    }
    puts("1");
}