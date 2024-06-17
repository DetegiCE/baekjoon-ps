x, y, m = map(int, input().split())
a = 0
for i in range(1001):
    for j in range(1001):
        z = i * x + j * y
        if z <= m:
            a = max(a, z)
print(a)
