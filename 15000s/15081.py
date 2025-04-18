n = int(input())
s = set()
b = []
for i in range(n):
    a = input().split()
    t = int(a[0])
    a = a[1:]
    for j in a:
        if j in s: continue
        b.append(j)
        s.add(j)
        break
print(*b)