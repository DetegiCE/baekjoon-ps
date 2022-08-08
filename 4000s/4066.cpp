#include<cstdio>
#include<vector>
using namespace std;

vector<char> vc;

void append(int a) {
    if (a == 27) vc.push_back(' ');
    else vc.push_back('A'+a-1);
}

void sol()
{
    vc.clear();
    int t;
    scanf("%d", &t);
    int a,b,c,d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    for(int ii=0 ; ii<t ; ii++) {
        int e;
        scanf("%d", &e);
        int r1 = e/1000000;
        int r2 = e%1000000/10000;
        int r3 = e%10000/100;
        int r4 = e%100;
        int flg = 0;
        for(int i=1 ; i<=27 ; i++) {
            for(int j=1 ; j<=27 ; j++) {
                for(int k=1 ; k<=27 ; k++) {
                    int num = i*10000 + j*100 + k;
                    if(num%a==r1 && num%b==r2 && num%c==r3 && num%d==r4) {
                        append(i);
                        append(j);
                        append(k);
                        flg = 1;
                        break;
                    }
                }
                if(flg == 1) break;
            }
            if(flg == 1) break;
        }
        
    }

}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--) {
        sol();
        while(vc.back() == ' ') vc.pop_back();
        for(int i=0 ; i<vc.size() ; i++) {
            printf("%c", vc[i]);
        }
        puts("");
    }
}