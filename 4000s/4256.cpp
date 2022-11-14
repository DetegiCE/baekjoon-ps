#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)

int n;
int pre[1003];
int inpos[1003];

void go(int inl, int inr, int prel, int prer) { // inorder pos
    if(inl > inr || prel > prer) return;
    // cout << '[' << inl << ' ' << inr << ' ' << prel << ' ' << prer << "]\n";
    if(prel == prer) {
        cout << pre[prel] << ' '; 
        return;
    }
    int incpos = inpos[pre[prel]];
    go(inl, incpos-1, prel+1, prel+incpos-inl);
    go(incpos+1, inr, prer-inr+incpos+1, prer);
    cout << pre[prel] << ' ';
}

void sol() {
    cin >> n;
    for(int i=0 ; i<n ; i++) cin >> pre[i];
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        inpos[t] = i;
    }
    go(0, n-1, 0, n-1);
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
}