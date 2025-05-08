r, c, k = map(int, input().split())
m = []
p = []
for i in range(r):
    a = input().split()
    m.append(list(a[0]))
    p.append(list(a[1]))

for i in range(r):
    if '*' not in p[i]:
        continue
    if '-' in m[i]:
        print('N')
        exit(0)
print('Y')