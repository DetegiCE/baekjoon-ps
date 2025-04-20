r, c, e, n = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(r)]
for _ in range(n):
    rs, cs, ds = map(int, input().split())
    rs -= 1
    cs -= 1
    mx = 0
    for i in range(rs, rs+3):
        for j in range(cs, cs+3):
            mx = max(mx, a[i][j])
    mx -= ds
    for i in range(rs, rs+3):
        for j in range(cs, cs+3):
            if a[i][j] > mx:
                a[i][j] = mx
for i in range(r):
    for j in range(c):
        if a[i][j] < e:
            a[i][j] = e - a[i][j]
        else: a[i][j] = 0
s = 0
for i in a:
    for j in i:
        s += j

print(s * 72 * 72)