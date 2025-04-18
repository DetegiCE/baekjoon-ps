n, d, k = map(int, input().split())
v = []
for i in range(n):
    a, b = input().split()
    b = int(b)
    v.append([b, a])
v.sort(key=lambda x: -x[0])

c = []
i = 0
while d > 0 and k > 0:
    d -= v[i][0]
    c.append(v[i][1])
    i += 1
    k -= 1

if d > 0:
    print('impossible')
else:
    print(len(c))
    for i in c:
        print(i + ", YOU ARE FIRED!")