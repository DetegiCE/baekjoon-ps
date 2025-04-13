n = int(input())
a = dict()
for _ in range(n):
    b = input()
    if b in a: a[b] += 1
    else: a[b] = 1
mx = max(a.values())
l = sorted(list(a.keys()))
for i in l:
    if a[i] == mx: print(i)