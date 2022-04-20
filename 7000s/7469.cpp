#include <cstdio>
#include <vector>
using namespace std;

int n, m;
int tst;
vector<int> v[263000];

void merge(int idx) {
    // printf("merge(%d)\n", idx);
    int lidx = idx * 2;
    int ridx = idx * 2 + 1;
    int lsz = v[lidx].size();
    int rsz = v[ridx].size();
    int lpos = 0;
    int rpos = 0;
    while (lpos < lsz && rpos < rsz) {
        if (v[lidx][lpos] < v[ridx][rpos]) {
            v[idx].push_back(v[lidx][lpos]);
            lpos++;
        } else {
            v[idx].push_back(v[ridx][rpos]);
            rpos++;
        }
    }
    while (lpos < lsz) v[idx].push_back(v[lidx][lpos]), lpos++;
    while (rpos < rsz) v[idx].push_back(v[ridx][rpos]), rpos++;
}

vector<int> search(int left, int right) {
    // printf("search(%d %d)\n", left, right);
    if (left > right) {
        return {};
    }
    if (left == right) {
        return v[left];
    }
    bool nleft = false, nright = false;
    if (left % 2 == 1) nleft = true;
    if (right % 2 == 0) nright = true;
    vector<int> nxt =
        search((left + (nleft ? 1 : 0)) / 2, (right - (nright ? 1 : 0)) / 2);
    vector<int> nv, mv;
    if (nleft) {
        int asz = v[left].size(), bsz = nxt.size();
        int apos = 0, bpos = 0;
        while (apos < asz && bpos < bsz) {
            if (v[left][apos] < nxt[bpos])
                nv.push_back(v[left][apos]), apos++;
            else
                nv.push_back(nxt[bpos]), bpos++;
        }
        while (apos < asz) nv.push_back(v[left][apos]), apos++;
        while (bpos < bsz) nv.push_back(nxt[bpos]), bpos++;
    } else {
        nv.assign(nxt.begin(), nxt.end());
    }
    if (nright) {
        int asz = v[right].size(), bsz = nv.size();
        int apos = 0, bpos = 0;
        while (apos < asz && bpos < bsz) {
            if (v[right][apos] < nv[bpos])
                mv.push_back(v[right][apos]), apos++;
            else
                mv.push_back(nv[bpos]), bpos++;
        }
        while (apos < asz) mv.push_back(v[right][apos]), apos++;
        while (bpos < bsz) mv.push_back(nv[bpos]), bpos++;
    } else {
        mv.assign(nv.begin(), nv.end());
    }
    return mv;
}

int main() {
    scanf("%d %d", &n, &m);
    for (tst = 1; tst < n; tst <<= 1)
        ;
    for (int i = tst; i < tst + n; i++) {
        int t;
        scanf("%d", &t);
        v[i].push_back(t);
    }
    for (int i = tst - 1; i >= 1; i--) merge(i);
    for (int i = 0; i < m; i++) {
        int p, q, r;
        scanf("%d %d %d", &p, &q, &r);
        vector<int> vs = search(p + tst - 1, q + tst - 1);
        printf("%d\n", vs[r - 1]);
    }
}