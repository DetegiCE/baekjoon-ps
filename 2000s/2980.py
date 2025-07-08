n, l = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
a.sort()
t = 0
pos = 0
for i in range(n):
    t += a[i][0] - pos
    pos = a[i][0]
    g = t % (a[i][1] + a[i][2])
    if g < a[i][1]:
        t += a[i][1] - g
t += l - pos
print(t)