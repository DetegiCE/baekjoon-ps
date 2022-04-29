#include<cstdio>
#include<utility>
using namespace std;
#define mp(A,B) (make_pair(A,B))
#define rf (r.first)
#define rs (r.second)

typedef pair<int, int> pii;

// 216 152
//   152 64
//     64 24
//       (1,-1) = 24 16

pii diophantine(int a, int b) {
    if (b % (a%b) == 0) return mp(1, -(a/b));
    pii r = diophantine(b, a%b);
    // a = 64, b = 24, r = (rf 1, rs -1)
    /*
    8 = rf(1) * b(24) + rs(-1) * a%b(16)
      = rf(1) * b(24) + rs(-1) * (a - b * (a/b))
      = rs(-1) * a(64) + (rf(1) + a/b) * b(24)
    */
    return mp(rs, rf + (-rs) * (a/b));
}

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main()
{
    int a, b, c;
    bool flip = false;
    scanf("%d %d %d", &a, &b, &c);
    if(c == 0) {
        printf("0 0");
        return 0;
    }
    if(a < b) {
        int tmp = a;
        a = b;
        b = tmp;
        flip = true;
    }
    if(a % b == 0) {
        if(c % b == 0) {
            if(flip) printf("%d 0\n", c/b);
            else printf("0 %d\n", c/b);
            return 0;
        }
        else {
            printf("Not Exist");
            return 0;
        }
    }
    pii r = diophantine(a, b);
    // printf("%d %d %d %d\n", rf, a, rs, b);
    int rans = rf * a + rs * b;
    if(c > 0) {
        int g = gcd(rans, c);
        int ng = c / g;
        if(!flip) printf("%d %d", rf * ng, rs * ng);
        else printf("%d %d", rs * ng, rf * ng);
    }
    else {
        int g = gcd(rans, -c);
        int ng = -c / g;
        if(!flip) printf("%d %d", rf * ng, rs * ng);
        else printf("%d %d", rs * ng, rf * ng);
    }
}