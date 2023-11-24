n = int(input())
pl = dict()
name = set()
for _ in range(n):
    n, p, t1, t2 = input().split()
    t1, t2 = int(t1), int(t2)
    if p not in pl:
        pl[p] = []
        for i in range(50001):
            pl[p].append(0)
    if n in name:
        continue
    name.add(n)
    for i in range(t1, t2):
        pl[p][i] += 1
mxp = 0
for p in pl:
    mxp = max(mxp, max(pl[p]))
pli = list(pl.items())
pli.sort(key=lambda x:x[0])
for i in pli:
    if max(i[1]) == mxp:
        print(i[0], end=' ')
        for j in range(1, 50001):
            if i[1][j-1] != mxp and i[1][j] == mxp:
                print(j, end=' ')
            if i[1][j] == mxp and i[1][j+1] != mxp:
                print(j+1)
                exit(0)
