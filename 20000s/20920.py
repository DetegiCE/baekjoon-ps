from sys import stdin
input = stdin.readline
n, m = map(int, input().split())
d = {}
for _ in range(n):
    a = input().rstrip()
    if len(a) < m:
        continue
    if a not in d:
        d[a] = 0
    d[a] += 1
v = list(d.items())
v.sort(key=lambda x: (-x[1], -len(x[0]), x[0]))
for i in v:
    print(i[0])
