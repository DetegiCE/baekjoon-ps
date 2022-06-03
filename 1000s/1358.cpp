#include<cstdio>

int w, h, x, y, p, xx, yy, cnt;

int dist(int x1, int y1, int x2, int y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

bool inRect() {
    return x <= xx && xx <= x+w && y <= yy && yy <= y+h;
}

bool inLeftCircle() {
    return xx <= x && dist(x, y+h/2, xx, yy) <= (h/2)*(h/2);
}

bool inRightCircle() {
    return x+w <= xx && dist(x+w, y+h/2, xx, yy) <= (h/2)*(h/2);
}

int main()
{
    scanf("%d %d %d %d %d", &w, &h, &x, &y, &p);
    while(p--) {
        scanf("%d %d", &xx, &yy);
        if(inRect() || inLeftCircle() || inRightCircle()) cnt++;
    }
    printf("%d", cnt);
}