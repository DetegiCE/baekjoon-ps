// unsolved!!!
// unsolved!!!
// unsolved!!!
// unsolved!!!
// unsolved!!!
// unsolved!!!
// unsolved!!!
// unsolved!!!
#include<cstdio>
#include<vector>
#include<map>
#include<utility>
using namespace std;

int n;

typedef struct POINT {
    int x, y;
} POINT;

typedef struct EDGE {
    int x, y;
    double tangent;
} EDGE;

int cnt;

vector<POINT> p;
vector<EDGE> e[1501][4];
// >0 <0 -- ||

double getTan(int x1, int y1, int x2, int y2) {
    return (double)(x1-x2)/(double)(y1-y2);
}

bool compare1(EDGE a, EDGE b) {
    return a.tangent > b.tangent;
}
bool compare2(EDGE a, EDGE b) {
    return a.tangent < b.tangent;
}

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        POINT np = {x, y};
        p.push_back(np);
    }

    for(int i=0 ; i<n ; i++) {
        map<double, int> mp;
        for(int j=0 ; j<n ; j++) {
            if(!(i-j)) continue;
            if(p[i].y == p[j].y) {
                EDGE ne = {p[j].x, p[j].y, 0};
                e[i][2].push_back(ne);
                continue;
            }
            if(p[i].x == p[j].x) {
                EDGE ne = {p[j].x, p[j].y, 0};
                e[i][3].push_back(ne);
                continue;
            }

            double tanv = getTan(p[i].x, p[i].y, p[j].x, p[j].y);

            map<double, int>::iterator it = mp.find(tanv);
            if(it != mp.end()) {
                (it->second)++;
            }
            else {
                mp.insert(make_pair(tanv, 1));
            }
        }
        cnt += e[i][2].size() * e[i][3].size();
        for(map<double, int>::iterator it = mp.begin(); it != mp.end() ; it++) {
            double finder = (it->first);
            int ficnt = (it->second);
            if(finder > 0) break;
            map<double, int>::iterator it2 = mp.find(-1.0/finder);
            if(it2 != mp.end()) {
                cnt += ficnt * (it2->second);
            }
        }
        mp.clear();
    }

    printf("%d", cnt);
}