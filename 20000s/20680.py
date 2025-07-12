from sys import stdin
input = stdin.readline
n, m = map(int, input().rstrip().split())
a = input().rstrip().split()
for _ in range(m):
    b = input().rstrip().split()
    c, d = b[0], b[1:]
    if c == 'insert':
        a.insert(int(d[1]), d[0])
    elif c == 'depart':
        a.remove(d[0])
    else:
        p = a.index(d[0]) + int(d[1])
        a.remove(d[0])
        a.insert(p, d[0])
print(*a)