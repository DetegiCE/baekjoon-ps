/**UNIT:1066 CodeUp:4421 BOJ:2667 JUNGOL:1695*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char maps[752][752];
int mapp[752][752];
int n, m;
int danji;
int iwlcntu[300000];

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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int i,j;
    cin >> n >> m;
    for(i=0 ; i<m ; i++){
        cin >> maps[i];
        for(j=0 ; j<n ; j++){
            if(maps[i][j] == '.') mapp[i][j] = 1;
            else mapp[i][j] = 0;
        }
    }
    danji=1;
    for(i=0 ; i<m ; i++){
        for(j=0 ; j<n ; j++){
            if(mapp[i][j]==1){
                danji++;
                apt(i,j);
            }
        }
    }

    for(i=0 ; i<m ; i++){
        for(j=0 ; j<n ; j++){
            if(mapp[i][j]>0){
                iwlcntu[mapp[i][j]-2]++;
            }
        }
    }

    sort(iwlcntu,iwlcntu+danji-1);
    
    cout << iwlcntu[danji-2];
}
