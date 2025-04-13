n, m = map(int, input().split())
cy, cx = 0, 0
s = 0
a = []
for _ in range(n):
    a.append(list(map(int, input().split())))
for _ in range(m):
    ny, nx, nmx = -1, -1, -1
    nidx = -1
    for idx, i in enumerate(a):
        dst = (cy-i[0])**2 + (cx-i[1])**2
        if dst > nmx:
            nmx = dst
            ny = i[0]
            nx = i[1]
            nidx = idx
    s += nmx
    cy, cx = ny, nx
    del a[nidx]
    a.append(list(map(int, input().split())))
print(s)