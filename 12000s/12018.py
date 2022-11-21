n, m = map(int, input().split())
a = []
for i in range(n):
    p, l = map(int, input().split())
    b = list(map(int, input().split()))
    b.sort()
    if p >= l:
        a.append(b[p-l])
    else:
        a.append(1)
a.sort()
s = 0
for i in range(n):
    s += a[i]
    if s > m:
        print(i)
        quit()
print(n)