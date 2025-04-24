n, k = map(int, input().split())
a = list(map(int, input().split()))
d = dict()
for i in a:
    if i in d: d[i] += 1
    else: d[i] = 1
e = list(map(list, d.items()))
e.sort()
for i in e:
    if k <= 0: break
    print(i[0], end=' ')
    i[1] -= 1
    k -= 1
for i in e:
    if k <= 0: break
    m = min(i[1], k)
    print((str(i[0])+' ') * m, end='')
    i[1] -= m
    k -= m