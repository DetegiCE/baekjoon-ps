n, m = map(int, input().split())
b = []
s = 0
for i in range(n):
    a = input().split()
    c = []
    for j in range(m):
        d = a[j].count('9')
        s += d
        c.append(d)
    b.append(c)
mx = 0
for i in range(n):
    mx = max(mx, sum(b[i]))
for i in range(m):
    ts = 0
    for j in range(n):
        ts += b[j][i]
    mx = max(mx, ts)
print(s - mx)
