a = list(sorted(input()))
b = list(sorted(input()))
c = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
d = [0 for _ in range(26)]
e = [0 for _ in range(26)]
for i in range(26):
    d[i] = a.count(c[i])
    e[i] = b.count(c[i])
d.sort()
e.sort()
if d == e: print('YES')
else: print('NO')