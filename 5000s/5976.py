n = int(input())
a = [[0 for _ in range(n)] for _ in range(n)]
cy, cx = 0, 0
d = 0
for p in range(n * n):
    a[cy][cx] = p + 1
    if d == 0:
        cx += 1
        if cx >= n or a[cy][cx] != 0:
            cx -= 1
            cy += 1
            d = 1
    elif d == 1:
        cy += 1
        if cy >= n or a[cy][cx] != 0:
            cx -= 1
            cy -= 1
            d = 2
    elif d == 2:
        cx -= 1
        if cx < 0 or a[cy][cx] != 0:
            cx += 1
            cy -= 1
            d = 3
    elif d == 3:
        cy -= 1
        if cy < 0 or a[cy][cx] != 0:
            cy += 1
            cx += 1
            d = 0
for i in range(n):
    print(*a[i])