n, m, s = map(int, input().split())
d1 = dict()
d2 = dict()
for _ in range(n):
    a, b, c = map(int, input().split())
    if a > 0:
        if c in d1: d1[c] += a
        else: d1[c] = a
    elif a < 0:
        if b in d2: d2[b] += a
        else: d2[b] = a
for i in range(1, m+1):
    if i in d2:
        s += d2[i]
    if s < 0:
        print('YES')
        exit(0)
    if i in d1:
        s += d1[i]
print('NO')