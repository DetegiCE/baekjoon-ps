#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y;
        char st[100001];
        scanf("%d %d", &x, &y);
        scanf(" %s", st);
        if (x == 0 && y == 0) {
            puts("Impossible");
            continue;
        }

        int slen = strlen(st);

        int v[4] = {0, 0, 0, 0};
        int curx = 0, cury = 0;

        for (int i = 0; i < slen; i++) {
            if (st[i] == 'L') curx--, v[0]++;
            if (st[i] == 'R') curx++, v[1]++;
            if (st[i] == 'U') cury++, v[2]++;
            if (st[i] == 'D') cury--, v[3]++;
        }
        if (curx == x && cury == y) {
            puts("Impossible");
            continue;
        }

        vector<int> dir = {1, 2, 3, 0};
        int boom = 0;
        do {
            boom = 0;
            int curx = 0, cury = 0;
            vector<char> aa;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < v[dir[i]]; j++) {
                    if (dir[i] == 0) aa.push_back('L');
                    if (dir[i] == 1) aa.push_back('R');
                    if (dir[i] == 2) aa.push_back('U');
                    if (dir[i] == 3) aa.push_back('D');
                }
            }
            for (int i = 0; i < slen; i++) {
                if (aa[i] == 'L') curx--;
                if (aa[i] == 'R') curx++;
                if (aa[i] == 'U') cury++;
                if (aa[i] == 'D') cury--;
                if (curx == x && cury == y) {
                    boom = 1;
                    break;
                }
            }
            if (boom == 0) {
                for (int i = 0; i < slen; i++) {
                    printf("%c", aa[i]);
                }
                puts("");
                break;
            }
        } while (next_permutation(dir.begin(), dir.end()));
        if (boom == 1) {
            puts("Impossible");
        }
    }
}