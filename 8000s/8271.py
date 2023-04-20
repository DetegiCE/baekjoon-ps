n = int(input())
a = []
r = []
for i in range(n):
    b = input()
    a.append(b)
    if 'W' in b:
        r.append(b.index('W'))
r.sort()
c = []
for i in range(n):
    if i not in r:
        c.append(i)
for i in range(n):
    if 'W' in a[i]:
        print(a[i])
    else:
        print('.'*c[0] + 'W' + '.'*(n-c[0]-1))
        c.pop(0)
