#include<cstdio>
#include<queue>
using namespace std;

typedef unsigned long long ull;

ull n;

struct Nums {
    ull val;
    int cnt;
};

// 11 111 111 111 111 111 111

int main()
{
    ull n;
    scanf("%llu", &n);
    Nums num = {1, 1};

    queue<Nums> q;
    q.push(num);
    while(!q.empty()) {
        Nums qf = q.front(); q.pop();
        if(qf.val % n == 0) {
            printf("%llu\n", qf.val);
            return 0;
        }

        if(qf.cnt == 20) continue;
        Nums num0 = {qf.val * 10, qf.cnt + 1};
        Nums num1 = {qf.val * 10 + 1, qf.cnt + 1};
        q.push(num0);
        q.push(num1);
    }
    puts("0");
    return 0;
}