#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> crain, box;
bool chk[10001];

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        int t;
        scanf("%d", &t);
        crain.push_back(t);
    }
    scanf("%d", &m);
    for(int i=0 ; i<m ; i++) {
        int t;
        scanf("%d", &t);
        box.push_back(t);
    }
    sort(crain.begin(), crain.end(), greater<int>());
    sort(box.begin(), box.end(), greater<int>());
    
    int leftfalse = 0;
    int crainnum = 0;
    int boxnum = 0;
    int cur = 0;
    int tim = 0;
    
    bool movelf = true;
    while(1) {
        //printf("%d %d\n", crainnum, boxnum);
        while(boxnum < m && crain[crainnum] < box[boxnum]) {
            boxnum++;
            movelf = false;
        }
        while(boxnum < m && chk[boxnum]) {
            boxnum++;
        }
        if(crainnum <n && boxnum < m && crain[crainnum] >= box[boxnum]) {
            chk[boxnum] = true;
            crainnum++;
            boxnum++;
            cur++;
            while(movelf && chk[leftfalse]) {
                leftfalse++;
                if(leftfalse == m) break;
            }
        }
        if(leftfalse == m) {
            printf("%d", tim + 1);
            break;
        }
        if(crainnum == 0 && cur == 0) {
            puts("-1");
            break;
        }
        if(crainnum == n || boxnum == m) {
            boxnum = leftfalse;
            movelf = true;
            tim++;
            cur=0;
            crainnum = 0;
        }
    }
}