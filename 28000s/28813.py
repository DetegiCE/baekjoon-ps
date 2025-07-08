t = int(input())
a = []
b = []
for _ in range(t):
    x, y = map(int, input().split())
    a.append(max(abs(x), abs(y)))
    b.append([max(abs(x), abs(y)), _+1])
b.sort()
c = []
d = 0
e = 0
for i in b:
    d += 1
    if d <= i[0]:
        c.append(i[1])
    else:
        e = -1
        break
if e == -1: print(-1)
else: print(*c)