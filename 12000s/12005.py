n, k = map(int, input().split())
a = []
for i in range(n):
    a.append(int(input()))

b = 0
for i in range(n):
    c = 0
    for j in range(n):
        if a[i] <= a[j] <= a[i] + k:
            c += 1
    b = max(b, c)
print(b)
