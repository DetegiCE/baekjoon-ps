from sys import stdin
input = stdin.readline
n = int(input())
d = dict()
for i in range(n):
    a, b = input().split()
    b = int(b)
    if a in d:
        d[a] += b
    else:
        d[a] = b
e = list(d.items())
e.sort()
for i in e:
    print(*i)