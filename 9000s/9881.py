n = int(input())
a = []
for i in range(n):
    a.append(int(input()))

mn = 1e18
for i in range(84):
    c = 0
    for j in range(n):
        x = 0
        if a[j] < i:
            x = i - a[j]
        elif a[j] > i + 17:
            x = a[j] - i - 17
        c += x**2
    mn = min(c, mn)

print(mn)
