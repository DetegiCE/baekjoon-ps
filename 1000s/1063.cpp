#include<bits/stdc++.h>
using namespace std;

int main()
{
    char k[3], d[3];
    int n;
    scanf("%s %s %d", k, d, &n);
    
    int king, dol;
    king = (k[0]-'A'+1)*10 + (k[1]-'0');
    dol = (d[0]-'A'+1)*10 + (d[1]-'0');
    for(int i=0 ; i<n ; i++) {
        char com[3];
        scanf(" %s", com);
        if(strcmp(com, "R") == 0) {
            if(king + 10 == dol) {
                if(dol + 10 > 88) {
                    continue;
                }
                else {
                    dol += 10;
                    king += 10;
                }
            }   
            else if(king + 10 <= 88) {
                king += 10;
            }
        }
        else if(strcmp(com, "L") == 0) {
            if(king - 10 == dol) {
                if(dol - 10 < 11) {
                    continue;
                }
                else {
                    dol -= 10;
                    king -= 10;
                }
            }
            else if(king - 10 >= 11) king -= 10;
        }
        else if(strcmp(com, "B") == 0) {
            if(king - 1 == dol) {
                if(dol % 10 == 1) continue;
                else {
                    king--;
                    dol--;
                }
            }
            else if(king % 10 > 1) king--;
        }
        else if(strcmp(com, "T") == 0) {
            if(king + 1 == dol) {
                if(dol % 10 == 8) continue;
                else {
                    king++;
                    dol++;
                }
            }
            else if(king % 10 < 8) king++;
        }
        else if(strcmp(com, "RT") == 0) {
            if(king + 11 == dol) {
                if(dol / 10 == 8 || dol % 10 == 8) continue;
                else {
                    king += 11;
                    dol += 11;
                }
            }
            else if(king / 10 < 8 && king % 10 < 8) king += 11;
        }
        else if(strcmp(com, "LT") == 0) {
            if(king - 9 == dol) {
                if(dol / 10 == 1 || dol % 10 == 8) continue;
                else {
                    king -= 9;
                    dol -= 9;
                }
            }   
            else if(king / 10 > 1 && king % 10 < 8) king -= 9;
        }
        else if(strcmp(com, "RB") == 0) {
            if(king + 9 == dol) {
                if(dol / 10 == 8 || dol % 10 == 1) continue;
                else {
                    king += 9;
                    dol += 9;
                }
            }   
            else if(king / 10 < 8 && king % 10 > 1) king += 9;
        }
        else {
            if(king - 11 == dol) {
                if(dol / 10 == 1 || dol % 10 == 1) continue;
                else {
                    king -= 11;
                    dol -= 11;
                }
            }
            else if(king / 10 > 1 && king % 10 > 1) king -= 11;
        }
    }
    printf("%c%d\n", (king/10)+'A'-1, (king%10));
    printf("%c%d", (dol/10)+'A'-1, dol%10);
}