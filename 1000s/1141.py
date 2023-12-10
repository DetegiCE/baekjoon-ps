n = int(input())
a = []
for i in range(n):
    a.append(input())
a.sort()
a = a[::-1]
c = '-'
b = 0
for i in range(n):
    if not c.startswith(a[i]):
        b += 1
        c = a[i]
print(b)
