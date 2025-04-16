n = int(input())
a = [int(input()) for _ in range(n)]
b = []
for i in a:
    b.append(i)
b.sort()
b.reverse()
d = dict()
for i in range(n):
    if b[i] not in d:
        d[b[i]] = i+1
for i in range(n):
    print(d[a[i]])
