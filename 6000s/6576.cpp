#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)

int n;
string st;
bool a[550][550];
int cur;

void f(int y, int x, int s) {
    cur++;
    if(st[cur] == 'Q') {
        f(y,x,s/2);
        f(y,x+s/2,s/2);
        f(y+s/2,x,s/2);
        f(y+s/2,x+s/2,s/2);
    }
    else if(st[cur] == 'B') {
        for(int i=y ; i<y+s ; i++) {
            for(int j=x ; j<x+s ; j++) {
                a[i][j] = true;
            }
        }
    }
}

void conv(int y, int x) {
    string cstr = "0123456789abcdef";
    int no = a[y][x] + a[y][x+1]*2 + a[y][x+2]*4 + a[y][x+3]*8;
    int np = a[y][x+4] + a[y][x+5]*2 + a[y][x+6]*4 + a[y][x+7]*8;
    cout << cstr[np] << cstr[no];
}

int main()
{
    INP;
    
    cin >> n;
    cin >> st;
    cur = -1;
    f(0,0,n);
    cout << "#define quadtree_width " << n;
    cout << "\n#define quadtree_height " << n;
    cout << "\nstatic char quadtree_bits[] = {\n";
    for(int i=0 ; i<n ; i++) {
        cout << "0x";
        for(int j=0 ; j<n ; j+=8) {
            conv(i, j);
            if(j != n-8) {
                cout << ",0x";
            }
        }
        cout << ",\n";
    }
    cout << "};";
}