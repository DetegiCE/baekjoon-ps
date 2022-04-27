#include<cstdio>

int up[4][4] = {{0,0,0},{0,0,0},{0,0,0}};
int down[4][4] = {{1,1,1},{1,1,1},{1,1,1}};
int front[4][4] = {{2,2,2},{2,2,2},{2,2,2}};
int back[4][4] = {{3,3,3},{3,3,3},{3,3,3}};
int left[4][4] = {{4,4,4},{4,4,4},{4,4,4}};
int right[4][4] = {{5,5,5},{5,5,5},{5,5,5}};
// 0 white , 1 yellow, 2 red, 3 orange, 4 green, 5 blue

void reset() {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            up[i][j] = 0;
            down[i][j] = 1;
            front[i][j] = 2;
            back[i][j] = 3;
            left[i][j] = 4;
            right[i][j] = 5;
        }
    }
}

void lplus() {
    int t1 = up[0][0], t2 = up[1][0], t3 = up[2][0], t4 = left[0][0], t5 = left[1][0];
    for(int i=0 ; i<3 ; i++) up[i][0] = back[i][0];
    for(int i=0 ; i<3 ; i++) back[i][0] = down[i][0];
    for(int i=0 ; i<3 ; i++) down[i][0] = front[i][0];
    front[0][0] = t1, front[1][0] = t2, front[2][0] = t3;
    left[0][0] = left[2][0];
    left[1][0] = left[2][1];
    left[2][0] = left[2][2];
    left[2][1] = left[1][2];
    left[2][2] = left[0][2];
    left[1][2] = left[0][1];
    left[0][2] = t4;
    left[0][1] = t5;
}

void lminus() {
    int t1 = up[0][0], t2 = up[1][0], t3 = up[2][0], t4 = left[0][0], t5 = left[0][1];
    for(int i=0 ; i<3 ; i++) up[i][0] = front[i][0];
    for(int i=0 ; i<3 ; i++) front[i][0] = down[i][0];
    for(int i=0 ; i<3 ; i++) down[i][0] = back[i][0];
    back[0][0] = t1, back[1][0] = t2, back[2][0] = t3;
    left[0][0] = left[0][2];
    left[0][1] = left[1][2];
    left[0][2] = left[2][2];
    left[1][2] = left[2][1];
    left[2][2] = left[2][0];
    left[2][1] = left[1][0];
    left[2][0] = t4;
    left[1][0] = t5;
}

void rplus() {
    int t1 = up[0][2], t2 = up[1][2], t3 = up[2][2], t4 = right[0][2], t5 = right[0][1];
    for(int i=0 ; i<3 ; i++) up[i][2] = front[i][2];
    for(int i=0 ; i<3 ; i++) front[i][2] = down[i][2];
    for(int i=0 ; i<3 ; i++) down[i][2] = back[i][2];
    back[0][2] = t1, back[1][2] = t2, back[2][2] = t3;
    right[0][2] = right[0][0];
    right[0][1] = right[1][0];
    right[0][0] = right[2][0];
    right[1][0] = right[2][1];
    right[2][0] = right[2][2];
    right[2][1] = right[1][2];
    right[2][2] = t4;
    right[1][2] = t5;
}

void rminus() {
    int t1 = up[0][2], t2 = up[1][2], t3 = up[2][2], t4 = right[0][0], t5 = right[0][1];
    for(int i=0 ; i<3 ; i++) up[i][2] = back[i][2];
    for(int i=0 ; i<3 ; i++) back[i][2] = down[i][2];
    for(int i=0 ; i<3 ; i++) down[i][2] = front[i][2];
    front[0][2] = t1, front[1][2] = t2, front[2][2] = t3;
    right[0][0] = right[0][2];
    right[0][1] = right[1][2];
    right[0][2] = right[2][2];
    right[1][2] = right[2][1];
    right[2][2] = right[2][0];
    right[2][1] = right[1][0];
    right[2][0] = t4;
    right[1][0] = t5;
}

void uplus() {
    int t1 = right[0][0], t2 = right[1][0], t3 = right[2][0], t4 = up[0][0], t5 = up[1][0];
    right[0][0] = back[2][0], right[1][0] = back[2][1], right[2][0] = back[2][2];
    back[2][0] = left[2][2], back[2][1] = left[1][2], back[2][2] = left[0][2];
    left[2][2] = front[0][2], left[1][2] = front[0][1], left[0][2] = front[0][0];
    front[0][0] = t3, front[0][1] = t2, front[0][2] = t1;
    up[0][0] = up[2][0];
    up[1][0] = up[2][1];
    up[2][0] = up[2][2];
    up[2][1] = up[1][2];
    up[2][2] = up[0][2];
    up[1][2] = up[0][1];
    up[0][2] = t4;
    up[0][1] = t5;
}

void uminus() {
    int t1 = right[0][0], t2 = right[1][0], t3 = right[2][0], t4 = up[0][2], t5 = up[1][2];
    right[0][0] = front[0][2], right[1][0] = front[0][1], right[2][0] = front[0][0];
    front[0][0] = left[0][2], front[0][1] = left[1][2], front[0][2] = left[2][2];
    left[0][2] = back[2][2], left[1][2] = back[2][1], left[2][2] = back[2][0];
    back[2][0] = t1, back[2][1] = t2, back[2][2] = t3;
    up[0][2] = up[2][2];
    up[1][2] = up[2][1];
    up[2][2] = up[2][0];
    up[2][1] = up[1][0];
    up[2][0] = up[0][0];
    up[1][0] = up[0][1];
    up[0][0] = t4;
    up[0][1] = t5;
}

void dplus() {
    int t1 = right[0][2], t2 = right[1][2], t3 = right[2][2], t4 = down[0][2], t5 = down[0][1];
    right[0][2] = front[2][2], right[1][2] = front[2][1], right[2][2] = front[2][0];
    front[2][0] = left[0][0], front[2][1] = left[1][0], front[2][2] = left[2][0];
    left[2][0] = back[0][0], left[1][0] = back[0][1], left[0][0] = back[0][2];
    back[0][0] = t1, back[0][1] = t2, back[0][2] = t3;
    down[0][2] = down[0][0];
    down[0][1] = down[1][0];
    down[0][0] = down[2][0];
    down[1][0] = down[2][1];
    down[2][0] = down[2][2];
    down[2][1] = down[1][2];
    down[2][2] = t4;
    down[1][2] = t5;
}

void dminus() {
    int t1 = right[0][2], t2 = right[1][2], t3 = right[2][2], t4 = down[0][0], t5 = down[0][1];
    right[0][2] = back[0][0], right[1][2] = back[0][1], right[2][2] = back[0][2];
    back[0][0] = left[2][0], back[0][1] = left[1][0], back[0][2] = left[0][0];
    left[2][0] = front[2][2], left[1][0] = front[2][1], left[0][0] = front[2][0];
    front[2][0] = t3, front[2][1] = t2, front[2][2] = t1;
    down[0][0] = down[0][2];
    down[0][1] = down[1][2];
    down[0][2] = down[2][2];
    down[1][2] = down[2][1];
    down[2][2] = down[2][0];
    down[2][1] = down[1][0];
    down[2][0] = t4;
    down[1][0] = t5;
}

void fplus() {
    int t1 = right[2][0], t2 = right[2][1], t3 = right[2][2], t4 = front[0][0], t5 = front[1][0];
    right[2][0] = up[2][0], right[2][1] = up[2][1], right[2][2] = up[2][2];
    up[2][0] = left[2][0], up[2][1] = left[2][1], up[2][2] = left[2][2];
    left[2][0] = down[0][2], left[2][1] = down[0][1], left[2][2] = down[0][0];
    down[0][0] = t3, down[0][1] = t2, down[0][2] = t1;
    front[0][0] = front[2][0];
    front[1][0] = front[2][1];
    front[2][0] = front[2][2];
    front[2][1] = front[1][2];
    front[2][2] = front[0][2];
    front[1][2] = front[0][1];
    front[0][2] = t4;
    front[0][1] = t5;
}

void fminus() {
    int t1 = right[2][0], t2 = right[2][1], t3 = right[2][2], t4 = front[0][0], t5 = front[0][1];
    right[2][0] = down[0][2], right[2][1] = down[0][1], right[2][2] = down[0][0];
    down[0][0] = left[2][2], down[0][1] = left[2][1], down[0][2] = left[2][0];
    left[2][0] = up[2][0], left[2][1] = up[2][1], left[2][2] = up[2][2];
    up[2][0] = t1, up[2][1] = t2, up[2][2] = t3;
    front[0][0] = front[0][2];
    front[0][1] = front[1][2];
    front[0][2] = front[2][2];
    front[1][2] = front[2][1];
    front[2][2] = front[2][0];
    front[2][1] = front[1][0];
    front[2][0] = t4;
    front[1][0] = t5;
}

void bplus() {
    int t1 = right[0][0], t2 = right[0][1], t3 = right[0][2], t4 = back[0][0], t5 = back[1][0];
    right[0][0] = down[2][2], right[0][1] = down[2][1], right[0][2] = down[2][0];
    down[2][0] = left[0][2], down[2][1] = left[0][1], down[2][2] = left[0][0];
    left[0][2] = up[0][2], left[0][1] = up[0][1], left[0][0] = up[0][0];
    up[0][0] = t1, up[0][1] = t2, up[0][2] = t3;
    back[0][0] = back[2][0];
    back[1][0] = back[2][1];
    back[2][0] = back[2][2];
    back[2][1] = back[1][2];
    back[2][2] = back[0][2];
    back[1][2] = back[0][1];
    back[0][2] = t4;
    back[0][1] = t5;
}
/*
2 L L 0 1 2 2 1 0
1 L L 1 F F R R 1
0 1 2 2 F F R R 2
L L 2 0 1 2 R R 2
L L 1 1 D D R R 1
2 1 0 2 D D 2 1 0 
2 1 0 0 1 2 2 R R
L L 1 1 B B 1 R R
L L 2 2 B B 0 1 2
0 1 2 0 1 2 0 1 2
1 L L 1 U U 1 R R
2 L L 2 U U 2 R R
*/
void bminus() {
    int t1 = right[0][0], t2 = right[0][1], t3 = right[0][2], t4 = back[0][0], t5 = back[0][1];
    right[0][0] = up[0][0], right[0][1] = up[0][1], right[0][2] = up[0][2];
    up[0][0] = left[0][0], up[0][1] = left[0][1], up[0][2] = left[0][2];
    left[0][2] = down[2][0], left[0][1] = down[2][1], left[0][0] = down[2][2];
    down[2][0] = t3, down[2][1] = t2, down[2][2] = t1;
    back[0][0] = back[0][2];
    back[0][1] = back[1][2];
    back[0][2] = back[2][2];
    back[1][2] = back[2][1];
    back[2][2] = back[2][0];
    back[2][1] = back[1][0];
    back[2][0] = t4;
    back[1][0] = t5;
}

void print() {
    for(int i=0 ; i<3 ; i++) {
        for(int j=0 ; j<3 ; j++) {
            if(up[i][j] == 0) printf("w");
            else if(up[i][j] == 1) printf("y");
            else if(up[i][j] == 2) printf("r");
            else if(up[i][j] == 3) printf("o");
            else if(up[i][j] == 4) printf("g");
            else if(up[i][j] == 5) printf("b");
        }
        puts("");
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        reset();
        int n;
        scanf("%d", &n);
        for(int i=0 ; i<n ; i++) {
            char a, b;
            scanf(" %c%c",&a,&b);
            if(a == 'L') {
                if(b == '+') lplus();
                else lminus();
            }
            else if(a == 'R') {
                if(b == '+') rplus();
                else rminus();
            }
            else if(a == 'U') {
                if(b == '+') uplus();
                else uminus();
            }
            else if(a == 'D') {
                if(b == '+') dplus();
                else dminus();
            }
            else if(a == 'F') {
                if(b == '+') fplus();
                else fminus();
            }
            else if(a == 'B') {
                if(b == '+') bplus();
                else bminus();
            }
        }
        print();
    }
}