n = int(input())
d = dict()
for _ in range(n):
    a, b = input().split()
    if b == '-': continue
    if b in d:
        d[b].append(a)
    else: d[b] = [a]
c = 0
for i in d:
    if len(d[i]) == 2:
        c += 1
print(c)
for i in d:
    if len(d[i]) == 2:
        print(d[i][0], d[i][1])