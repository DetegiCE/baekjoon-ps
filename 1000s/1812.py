n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
s = sum(a) // 2
for i in range(n):
    t = 0
    for j in range(i+1, n, 2):
        t += a[j]
    for j in range(i%2, i, 2):
        t += a[j]
    print(s - t)