n = int(input())
k = int(input())
d = dict()
for _ in range(n):
    a = int(input())
    if a in d: d[a] += 1
    else: d[a] = 1
b = list(d.items())
b.sort(reverse=True)
c = 0
for i in b:
    if k <= 0: break
    c += i[1]
    k -= i[1]
print(c)