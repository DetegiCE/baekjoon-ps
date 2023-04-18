n, a, b = input().split()
n = int(n)
a = list(a)
b = list(b)
r, s = 0, 0
for i in range(n):
    if a[i] == b[i]:
        r += 1
        a[i] = '-'
        b[i] = '_'
for i in range(n):
    for j in range(n):
        if a[i] == b[j]:
            s += 1
            a[i] = '-'
            b[j] = '_'
            break
print(r, s)
