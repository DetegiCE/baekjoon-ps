a = input()
l = len(a) // 2
a += a
c = 0
for i in range(l):
    if a[i] == 'B':
        c += 1
m = c
for i in range(l, l*3):
    if a[i] == 'B': c += 1
    if a[i-l] == 'B': c -= 1
    m = max(m, c)
print(m)
