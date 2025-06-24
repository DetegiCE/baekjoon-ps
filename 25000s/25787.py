s, n = map(int, input().split())
f = [list(map(int, input().split())) for _ in range(n)]
mx = 0
for x in range(101):
    for y in range(101):
        c = 0
        for j in range(n):
            if x <= f[j][0] <= x + s and y <= f[j][1] <= y + s:
                c += 1
        mx = max(mx, c)
print(mx)