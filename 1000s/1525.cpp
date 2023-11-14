#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
set<int> st;
queue<pii> q;

int up(int v) {
    int ov = v;
    int a[10] = {0};
    int cnt = 9;
    while(v > 0) {
        a[cnt] = v % 10;
        cnt--;
        v /= 10;
    }
    int zpos = -1;
    for(int i=1 ; i<=9 ; i++) {
        if(a[i] == 0) {
            zpos = i;
            break;
        }
    }
    if(zpos <= 3) return -1;
    else {
        int tmp = a[zpos];
        a[zpos] = a[zpos-3];
        a[zpos-3] = tmp;
        int r = 0;
        for(int i=1 ; i<=9 ; i++) {
            r *= 10;
            r += a[i];
        }
        return r;
    }
}

int down(int v) {
    int ov = v;
    int a[10] = {0};
    int cnt = 9;
    while(v > 0) {
        a[cnt] = v % 10;
        cnt--;
        v /= 10;
    }
    int zpos = -1;
    for(int i=1 ; i<=9 ; i++) {
        if(a[i] == 0) {
            zpos = i;
            break;
        }
    }
    if(zpos >= 7) return -1;
    else {
        int tmp = a[zpos];
        a[zpos] = a[zpos+3];
        a[zpos+3] = tmp;
        int r = 0;
        for(int i=1 ; i<=9 ; i++) {
            r *= 10;
            r += a[i];
        }
        return r;
    }
}

int left(int v) {
    int ov = v;
    int a[10] = {0};
    int cnt = 9;
    while(v > 0) {
        a[cnt] = v % 10;
        cnt--;
        v /= 10;
    }
    int zpos = -1;
    for(int i=1 ; i<=9 ; i++) {
        if(a[i] == 0) {
            zpos = i;
            break;
        }
    }
    if(zpos % 3 == 1) return -1;
    else {
        int tmp = a[zpos];
        a[zpos] = a[zpos-1];
        a[zpos-1] = tmp;
        int r = 0;
        for(int i=1 ; i<=9 ; i++) {
            r *= 10;
            r += a[i];
        }
        return r;
    }
}

int right(int v) {
    int ov = v;
    int a[10] = {0};
    int cnt = 9;
    while(v > 0) {
        a[cnt] = v % 10;
        cnt--;
        v /= 10;
    }
    int zpos = -1;
    for(int i=1 ; i<=9 ; i++) {
        if(a[i] == 0) {
            zpos = i;
            break;
        }
    }
    if(zpos % 3 == 0) return -1;
    else {
        int tmp = a[zpos];
        a[zpos] = a[zpos+1];
        a[zpos+1] = tmp;
        int r = 0;
        for(int i=1 ; i<=9 ; i++) {
            r *= 10;
            r += a[i];
        }
        return r;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 0;
    for(int i=0 ; i<9 ; i++) {
        t *= 10;
        int p;
        cin >> p;
        t += p;
    }
    
    if(t == 123456780) {
        cout << 0;
        return 0;
    }
    st.insert(t);
    q.push(pii(t, 0));
    while(!q.empty()) {
        pii qf = q.front();
        int qfv = qf.first;
        int qft = qf.second;
        // cout << qfv << ' ' << qft << '\n';
        q.pop();
        
        int uu = up(qfv);
        int dd = down(qfv);
        int ll = left(qfv);
        int rr = right(qfv);
        if(uu == 123456780) {
            cout << qft + 1;
            return 0;
        }
        if(dd == 123456780) {
            cout << qft + 1;
            return 0;
        }
        if(ll == 123456780) {
            cout << qft + 1;
            return 0;
        }
        if(rr == 123456780) {
            cout << qft + 1;
            return 0;
        }
        if(uu != -1 && st.find(uu) == st.end()) {
            st.insert(uu);
            q.push(pii(uu, qft + 1));
        }
        if(dd != -1 && st.find(dd) == st.end()) {
            st.insert(dd);
            q.push(pii(dd, qft + 1));
        }
        if(ll != -1 && st.find(ll) == st.end()) {
            st.insert(ll);
            q.push(pii(ll, qft + 1));
        }
        if(rr != -1 && st.find(rr) == st.end()) {
            st.insert(rr);
            q.push(pii(rr, qft + 1));
        }
    }
    cout << -1;
}
