n, m = map(int, input().split())
a = []
for _ in range(n):
    a.append(list(map(int, input().split())))
c = 1
for i in range(1, n):
    chk = True
    for j in range(m):
        d = a[i][j]
        if d != 100 and a[0][j] == 100:
            chk = False
    if chk:
        c += 1
print(1, c)
