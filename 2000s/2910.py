n, c = map(int, input().split())
d = {}
chk = set()
a = list(map(int, input().split()))
cnts = [[] for _ in range(1001)]
for i in a:
    if i not in d:
        d[i] = 0
    d[i] += 1
for i in a:
    if i not in chk:
        cnts[d[i]].append(i)
        chk.add(i)
for i in range(1000, 0, -1):
    for j in cnts[i]:
        for k in range(i):
            print(j, end=' ')
