r, c = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(r)]
ans = 0
for i in range(r):
    for j in range(c):
        f = 0
        for k in range(j):
            if a[i][j] <= a[i][k]:
                f = 1
                break
        if f == 0:
            ans += 1
        f = 0
        for k in range(j+1, c):
            if a[i][j] <= a[i][k]:
                f = 1
                break
        if f == 0:
            ans += 1
        f = 0
        for k in range(i):
            if a[i][j] <= a[k][j]:
                f = 1
                break
        if f == 0:
            ans += 1
        f = 0
        for k in range(i+1, r):
            if a[i][j] <= a[k][j]:
                f = 1
                break
        if f == 0:
            ans += 1
print(ans)