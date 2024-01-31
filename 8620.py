d = {}
for _ in range(int(input())):
    a, b = input().split()
    b = int(b)
    if a in d:
        d[a] += b
    else:
        d[a] = b
c = list(d.items())
c.sort(key=lambda x: x[0])
for i in c:
    if i[1] > 0:
        print(i[0], i[1])
