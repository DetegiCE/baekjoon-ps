x, k = map(int, input().split())
a = list(map(int, input().split()))
l = [0] * (k+1)
r = [0] * (k+1)
for i in range(x):
    l[a[i]] += 1
for i in range(x):
    r[a[i+x]] += 1
c = 0
for i in range(k+1):
    c += l[i] * r[i]
print(x**2-c)