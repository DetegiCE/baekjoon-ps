#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int r, c;

void f() {
    string mapp[77];
    string com;
    for(int i=0 ; i<r ; i++) {
        for(int j=0 ; j<c ; j++) {
            mapp[i] += " ";
        }
    }
    while(true) {
        cin >> com;
        if(com == "PRINT") {
            cout << "+";
            for(int i=0 ; i<c ; i++) cout << "-";
            cout << "+\n";
            for(int i=0 ; i<r ; i++) {
                cout << "|";
                for(int j=0 ; j<c ; j++) {
                    cout << mapp[i][j];
                }
                cout << "|\n";
            }
            cout << "+";
            for(int i=0 ; i<c ; i++) cout << "-";
            cout << "+\n";
            cin >> c >> r;
            return;
        }
        else if(com == "POINT") {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            if(mapp[y][x] == 'o') mapp[y][x] = 'o';
            else if(mapp[y][x] != ' ') mapp[y][x] = '*';
            else mapp[y][x] = 'o';
        }
        else if(com == "TEXT") {
            int x, y;
            string text;
            cin >> x >> y >> text;
            x--;
            y--;
            int tlen = text.length();
            for(int i=x ; i<min(x+tlen, c); i++) {
                if(mapp[y][i] == text[i-x]) mapp[y][i] = text[i-x];
                else if(mapp[y][i] != ' ') mapp[y][i] = '*';
                else mapp[y][i] = text[i-x];
            }
        }
        else if(com == "LINE") {
            int ax, ay, bx, by;
            char cs = '-';
            cin >> ax >> ay >> bx >> by;
            ax--;
            ay--;
            bx--;
            by--;
            if(ax == bx) cs = '|';
            else if(ay == by) cs = '-';
            else if(ax-bx == ay-by) cs = '\\';
            else cs = '/';
            if(cs == '|') {
                for(int i=min(ay, by) ; i<=max(ay, by) ; i++) {
                    if(mapp[i][ax] == '-') mapp[i][ax] = '+';
                    else if(mapp[i][ax] == ' ') mapp[i][ax] = '|';
                    else if(mapp[i][ax] == '|') mapp[i][ax] = '|';
                    else if(mapp[i][ax] == '/') mapp[i][ax] = '*';
                    else if(mapp[i][ax] == '\\') mapp[i][ax] = '*';
                    else if(mapp[i][ax] == 'o') mapp[i][ax] = '*';
                    else if(mapp[i][ax] == 'x') mapp[i][ax] = '*';
                    else if(mapp[i][ax] == '+') mapp[i][ax] = '+';
                    else mapp[i][ax] = '*';
                }
            }
            else if(cs == '-') {
                for(int i=min(ax, bx) ; i<=max(ax, bx) ; i++) {
                    if(mapp[ay][i] == '-') mapp[ay][i] = '-';
                    else if(mapp[ay][i] == ' ') mapp[ay][i] = '-';
                    else if(mapp[ay][i] == '|') mapp[ay][i] = '+';
                    else if(mapp[ay][i] == '/') mapp[ay][i] = '*';
                    else if(mapp[ay][i] == '\\') mapp[ay][i] = '*';
                    else if(mapp[ay][i] == 'o') mapp[ay][i] = '*';
                    else if(mapp[ay][i] == 'x') mapp[ay][i] = '*';
                    else if(mapp[ay][i] == '+') mapp[ay][i] = '+';
                    else mapp[ay][i] = '*';
                }
            }
            else if(cs == '\\') {
                for(int i=0 ; i<=abs(ax-bx) ; i++) {
                    int ty = min(ay, by) + i;
                    int tx = min(ax, bx) + i;
                    if(mapp[ty][tx] == '-') mapp[ty][tx] = '*';
                    else if(mapp[ty][tx] == ' ') mapp[ty][tx] = '\\';
                    else if(mapp[ty][tx] == '|') mapp[ty][tx] = '*';
                    else if(mapp[ty][tx] == '/') mapp[ty][tx] = 'x';
                    else if(mapp[ty][tx] == '\\') mapp[ty][tx] = '\\';
                    else if(mapp[ty][tx] == 'o') mapp[ty][tx] = '*';
                    else if(mapp[ty][tx] == 'x') mapp[ty][tx] = 'x';
                    else if(mapp[ty][tx] == '+') mapp[ty][tx] = '*';
                    else mapp[ty][tx] = '*';
                }
            }
            else {
                for(int i=0 ; i<=abs(ax-bx) ; i++) {
                    int ty = min(ay, by) + i;
                    int tx = max(ax, bx) - i;
                    if(mapp[ty][tx] == '-') mapp[ty][tx] = '*';
                    else if(mapp[ty][tx] == ' ') mapp[ty][tx] = '/';
                    else if(mapp[ty][tx] == '|') mapp[ty][tx] = '*';
                    else if(mapp[ty][tx] == '/') mapp[ty][tx] = '/';
                    else if(mapp[ty][tx] == '\\') mapp[ty][tx] = 'x';
                    else if(mapp[ty][tx] == 'o') mapp[ty][tx] = '*';
                    else if(mapp[ty][tx] == 'x') mapp[ty][tx] = 'x';
                    else if(mapp[ty][tx] == '+') mapp[ty][tx] = '*';
                    else mapp[ty][tx] = '*';
                }
            }
        }
        else if(com == "CLEAR") {
            int ax, ay, bx, by;
            cin >> ax >> ay >> bx >> by;
            ax--;
            ay--;
            bx--;
            by--;
            for(int i=min(ay, by) ; i<=max(ay, by) ; i++) {
                for(int j=min(ax, bx) ; j<=max(ax, bx) ; j++) {
                    mapp[i][j] = ' ';
                }
            }
        }
        cin.ignore();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> c >> r;
    while(true) {
        if(c == 0 && r == 0) break;
        f();
        cout << "\n";
    }
}
