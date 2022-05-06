#include<cstdio>

#define SQ2(k) ((1 << (k)))

int k, h;
char comm[18];
int stx, sty, enx, eny;
int mapp[258][258];

int main()
{
    scanf("%d", &k);
    stx = sty = 0;
    enx = eny = SQ2(k) - 1;
    for(int i=0 ; i<2*k ; i++) {
        scanf(" %c", &comm[i]);
        if(comm[i] == 'D') sty += (eny - sty + 1) / 2;
        else if(comm[i] == 'U') eny -= (eny - sty + 1) / 2;
        else if(comm[i] == 'R') stx += (enx - stx + 1) / 2;
        else enx -= (enx - stx + 1) / 2;
    }
    scanf("%d", &h);
    mapp[eny][enx] = h;
    for(int i=2*k-1 ; i>=0 ; i--) {
        if(comm[i] == 'D') {
            for(int j=sty ; j<=eny ; j++) {
                for(int k=stx ; k<=enx ; k++) {
                    if(mapp[j][k] == 0) mapp[sty-(j-sty+1)][k] = 2;
                    if(mapp[j][k] == 1) mapp[sty-(j-sty+1)][k] = 3;
                    if(mapp[j][k] == 2) mapp[sty-(j-sty+1)][k] = 0;
                    if(mapp[j][k] == 3) mapp[sty-(j-sty+1)][k] = 1;
                }
            }
            sty -= (eny - sty + 1);
        }
        if(comm[i] == 'U') {
            for(int j=sty ; j<=eny ; j++) {
                for(int k=stx ; k<=enx ; k++) {
                    if(mapp[j][k] == 0) mapp[eny+(eny-sty+1)-(j-sty)][k] = 2;
                    if(mapp[j][k] == 1) mapp[eny+(eny-sty+1)-(j-sty)][k] = 3;
                    if(mapp[j][k] == 2) mapp[eny+(eny-sty+1)-(j-sty)][k] = 0;
                    if(mapp[j][k] == 3) mapp[eny+(eny-sty+1)-(j-sty)][k] = 1;
                }
            }
            eny += (eny - sty + 1);
        }
        if(comm[i] == 'R') {
            for(int j=sty ; j<=eny ; j++) {
                for(int k=stx ; k<=enx ; k++) {
                    if(mapp[j][k] == 0) mapp[j][stx-(k-stx+1)] = 1;
                    if(mapp[j][k] == 1) mapp[j][stx-(k-stx+1)] = 0;
                    if(mapp[j][k] == 2) mapp[j][stx-(k-stx+1)] = 3;
                    if(mapp[j][k] == 3) mapp[j][stx-(k-stx+1)] = 2;
                }
            }
            stx -= (enx - stx + 1);
        }
        if(comm[i] == 'L') {
            for(int j=sty ; j<=eny ; j++) {
                for(int k=stx ; k<=enx ; k++) {
                    if(mapp[j][k] == 0) mapp[j][enx+(enx-stx+1)-(k-stx)] = 1;
                    if(mapp[j][k] == 1) mapp[j][enx+(enx-stx+1)-(k-stx)] = 0;
                    if(mapp[j][k] == 2) mapp[j][enx+(enx-stx+1)-(k-stx)] = 3;
                    if(mapp[j][k] == 3) mapp[j][enx+(enx-stx+1)-(k-stx)] = 2;
                }
            }
            enx += (enx - stx + 1);
        }
    }
    for(int i=0 ; i<SQ2(k) ; i++) {
        for(int j=0 ; j<SQ2(k) ; j++) {
            printf("%d ", mapp[i][j]);
        }
        puts("");
    }
}