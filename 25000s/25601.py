n = int(input())
d = dict()
for _ in range(n-1):
    a, b = input().split()
    d[a] = b
a, b = input().split()
ta, tb = a, b
c = b
while True:
    if c == a:
        print(1)
        exit(0)
    if c not in d:
        break
    c = d[c]
a, b = tb, ta
c = b
while True:
    if c == a:
        print(1)
        break
    if c not in d:
        print(0)
        break
    c = d[c]