#include<cstdio>

bool leap(int year) {
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
    else return false;
}

int main()
{
    int y1, m1, d1, y2, m2, d2;
    scanf("%d %d %d", &y1, &m1, &d1);
    scanf("%d %d %d", &y2, &m2, &d2);

    int months[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int lonths[15] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(y1 + 1000 == y2) {
        if(m1 == m2) {
            if(d1 <= d2) {
                puts("gg");
                return 0;
            }
        }
        else if(m1 < m2) {
            puts("gg");
            return 0;
        }
    }
    if(y1 + 1000 < y2) {
        puts("gg");
        return 0;
    }

    int starts = d1;
    int ends = d2;

    for(int i=1 ; i<y1 ; i++) {
        if(leap(i)) starts += 366;
        else starts += 365;
    }
    for(int i=1 ; i<y2 ; i++) {
        if(leap(i)) ends += 366;
        else ends += 365;
    }

    for(int i=1 ; i<m1 ; i++) {
        if(leap(y1)) starts += lonths[i];
        else starts += months[i];
    }
    for(int i=1 ; i<m2 ; i++) {
        if(leap(y2)) ends += lonths[i];
        else ends += months[i];
    }

    printf("D-%d", ends-starts);
}