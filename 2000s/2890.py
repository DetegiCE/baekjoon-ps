r, c = map(int, input().split())
pos = {}
rnk = [0,0,0,0,0,0,0,0,0,0]
for _ in range(r):
    a = input()
    a = a[1:-1]
    b = a.lstrip('.')
    if len(b) == 0:
        continue
    pos[int(b[0])] = c - len(b)
sp = sorted(list(pos.items()), key=lambda x: -x[1])
rkv = 1
rnk[sp[0][0]] = 1
for i in range(1, 9):
    if sp[i][1] == sp[i-1][1]:
        rnk[sp[i][0]] = rnk[sp[i-1][0]]
    else:
        rkv += 1
        rnk[sp[i][0]] = rkv
for i in range(1, 10):
    print(rnk[i])
