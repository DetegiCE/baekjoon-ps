#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

#define mp(A,B) make_pair(A,B)
#define FF first
#define SS second

#define MIN(A,B) ((A)>(B)?(B):(A))

typedef pair<int, int> pii;
typedef pair<int, pii> pip;

int x, y, n;
vector<pip> garo, sero;

int minarea = 1000000000;
int ming1, ming2, mins1, mins2;

bool check(int g1, int g2, int s1, int s2) {
    bool g1s1, g1s2, g2s1, g2s2;
    bool s1g1, s1g2, s2g1, s2g2;
    g1s1 = (sero[s1].SS.FF <= garo[g1].FF && garo[g1].FF <= sero[s1].SS.SS);
    g1s2 = (sero[s2].SS.FF <= garo[g1].FF && garo[g1].FF <= sero[s2].SS.SS);
    g2s1 = (sero[s1].SS.FF <= garo[g2].FF && garo[g2].FF <= sero[s1].SS.SS);
    g2s2 = (sero[s2].SS.FF <= garo[g2].FF && garo[g2].FF <= sero[s2].SS.SS);
    s1g1 = (garo[g1].SS.FF <= sero[s1].FF && sero[s1].FF <= garo[g1].SS.SS);
    s1g2 = (garo[g2].SS.FF <= sero[s1].FF && sero[s1].FF <= garo[g2].SS.SS);
    s2g1 = (garo[g1].SS.FF <= sero[s2].FF && sero[s2].FF <= garo[g1].SS.SS);
    s2g2 = (garo[g2].SS.FF <= sero[s2].FF && sero[s2].FF <= garo[g2].SS.SS);
    return (g1s1 && g1s2 && g2s1 && g2s2 && s1g1 && s1g2 && s2g1 && s2g2);
}

int getarea(int g1, int g2, int s1, int s2) {
    return (sero[s2].FF - sero[s1].FF) * (garo[g2].FF - garo[g1].FF);
}

void savepoint(int g1, int g2, int s1, int s2) {
    ming1 = g1;
    ming2 = g2;
    mins1 = s1;
    mins2 = s2;
    return;
}

void getpoint(int g1, int g2, int s1, int s2) {
    printf("%d %d\n", sero[s1].FF, garo[g1].FF);
    printf("%d %d\n", sero[s2].FF, garo[g2].FF);
    return;
}

int main()
{
    scanf("%d %d", &x, &y);
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        char d;
        int a;
        scanf(" %c %d", &d, &a);
        if(d == 'L') {
            garo.push_back(mp(y, mp(x-a, x)));
            x -= a;
        }
        if(d == 'R') {
            garo.push_back(mp(y, mp(x, x+a)));
            x += a;
        }
        if(d == 'U') {
            sero.push_back(mp(x, mp(y, y+a)));
            y += a;
        }
        if(d == 'D') {
            sero.push_back(mp(x, mp(y-a, y)));
            y -= a;
        }
    }
    sort(garo.begin(), garo.end());
    sort(sero.begin(), sero.end());
    // for(int i = 0; i < garo.size(); i++) {
    //     printf("%d %d %d\n", garo[i].first, garo[i].second.first, garo[i].second.second);
    // }
    // for(int i = 0; i < sero.size(); i++) {
    //     printf("%d %d %d\n", sero[i].first, sero[i].second.first, sero[i].second.second);
    // }
    for(int i=0 ; i<n/2 ; i++) {
        for(int j=i+1 ; j<n/2 ; j++) {
            for(int k=0 ; k<n/2 ; k++) {
                for(int l=k+1 ; l<n/2 ; l++) {
                    if(check(i, j, k, l) && minarea > getarea(i, j, k, l)) {
                        minarea = getarea(i, j, k, l);
                        savepoint(i, j, k, l);
                    }
                }
            }
        }
    }
    if(minarea == 1000000000) {
        printf("0\n");
    }
    else {
        getpoint(ming1, ming2, mins1, mins2);
    }
    return 0;
}

/*
10 10
6
R 10
U 11
R 1
D 1
L 11
D 10
*/