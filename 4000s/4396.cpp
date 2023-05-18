#include<bits/stdc++.h>
using namespace std;

int n;
string a[11], b[11];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        cin.ignore();
        cin >> a[i];
    }
    for(int i=0 ; i<n ; i++) {
        cin.ignore();
        cin >> b[i];
    }
    
    bool ism = false;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            if(b[i][j] == 'x' && a[i][j] == '*') {
                ism = true;
            }
        }
    }
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            if(ism) {
                if(a[i][j] == '*') cout << '*';
                else if(b[i][j] == '.') cout << '.';
                else {
                    int c = 0;
                    for(int k=0 ; k<8 ; k++) {
                        int nx = j+dx[k];
                        int ny = i+dy[k];
                        if(0 <= nx && nx < n && 0 <= ny && ny < n && a[ny][nx] == '*') {
                            c++;
                        }
                    }
                    cout << c;
                } 
            }
            else {
                if(b[i][j] == '.') cout << '.';
                else {
                    int c = 0;
                    for(int k=0 ; k<8 ; k++) {
                        int nx = j+dx[k];
                        int ny = i+dy[k];
                        if(0 <= nx && nx < n && 0 <= ny && ny < n && a[ny][nx] == '*') {
                            c++;
                        }
                    }
                    cout << c;
                    
                }
            }
        }
        cout << '\n';
    }
}
