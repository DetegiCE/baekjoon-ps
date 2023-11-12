n = int(input())
d = dict()
for _ in range(n):
    a, b = input().split()
    d[a] = b
m = int(input())
for _ in range(m):
    a = input()
    if a in d:
        print(d[a], end='')
    else:
        print(a, end='')
