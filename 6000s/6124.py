nr, nc = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(nr)]

mx = -1
mi = -1
mj = -1
for i in range(nr-2):
    for j in range(nc-2):
        s = 0
        for k in range(3):
            for l in range(3):
                s += a[i+k][j+l]
        if s > mx:
            mx = s
            mi = i
            mj = j
print(mx)
print(mi+1, mj+1)