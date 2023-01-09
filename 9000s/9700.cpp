#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int mapp[45][45];
int n;
int danji;

void apt(int y,int x)
{
    int dy[8]={-1,-1,-1,0,0,1,1,1};
    int dx[8]={-1,0,1,-1,1,-1,0,1};
    int i;
    mapp[y][x]=danji;
    for(i=0 ; i<8 ; i++){
        if(mapp[y+dy[i]][x+dx[i]]==1) apt(y+dy[i],x+dx[i]);
    }
}

int main()
{
    int i,j, c=0;
    while(cin>>n) {
        for(i=0 ; i<n ; i++){
            for(j=0 ; j<n ; j++){
                scanf("%1d",&mapp[i][j]);
            }
        }
        for(int i=0 ; i<n+1 ; i++) mapp[n][i] = mapp[i][n] = 0;
        danji=1;
        for(i=0 ; i<n ; i++){
            for(j=0 ; j<n ; j++){
                if(mapp[i][j]==1){
                    danji++;
                    apt(i,j);
                }
            }
        }
        c++;
        cout << "Case #" << c << ": ";
        cout << danji-1 << '\n';
    }
}
