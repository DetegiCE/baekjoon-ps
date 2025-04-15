a = input().split()
b, c = input().split()
d = ''
e = ''
for i in b: d += str(a.index(i))
for i in c: e += str(a.index(i))
f = str(int(d) + int(e))
for i in f:
    print(a[int(i)], end='')