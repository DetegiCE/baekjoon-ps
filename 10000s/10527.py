n = int(input())
d = dict()
k = dict()
for _ in range(n):
    s = input()
    if s in d: d[s] += 1
    else: d[s] = 1
for _ in range(n):
    s = input()
    if s in k: k[s] += 1
    else: k[s] = 1

a = 0
for i in d:
    if i in k:
        a += min(d[i], k[i])
print(a)