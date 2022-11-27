#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int mapp[502][502];
int n, m;
int danji;
int iwlcntu[250002];

void apt(int y,int x)
{
    int dy[4]={ 0,-1, 0, 1};
    int dx[4]={-1, 0, 1, 0};
    int i;
    mapp[y][x]=danji;
    for(i=0 ; i<4 ; i++){
        if(mapp[y+dy[i]][x+dx[i]]==1) apt(y+dy[i],x+dx[i]);
    }
}

int main()
{
    int i,j;
    cin >> n >> m;
    for(i=0 ; i<n ; i++){
        for(j=0 ; j<m ; j++){
            cin >> mapp[i][j];
        }
    }
    danji=1;
    for(i=0 ; i<n ; i++){
        for(j=0 ; j<m ; j++){
            if(mapp[i][j]==1){
                danji++;
                apt(i,j);
            }
        }
    }

    for(i=0 ; i<n ; i++){
        for(j=0 ; j<m ; j++){
            if(mapp[i][j]>0){
                iwlcntu[mapp[i][j]-2]++;
            }
        }
    }

    sort(iwlcntu,iwlcntu+danji-1);

    cout << danji-1 << '\n' << iwlcntu[danji-2];
}
