n, m = map(int, input().split())
a = []
for i in range(n):
    a.append(list(map(int, input().split())))
mx = 0
for i in range(m):
    for j in range(i+1, m):
        for k in range(j+1, m):
            s = 0
            for l in range(n):
                s += max(a[l][i], a[l][j], a[l][k])
            mx = max(mx, s)
print(mx)