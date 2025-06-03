n = int(input())
a = [tuple(map(int, input().split())) for _ in range(n)]

b = []
for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            x1, y1 = a[i]
            x2, y2 = a[j]
            x3, y3 = a[k]
            if (x1 - x2)*(y2 - y3) == (y1 - y2)*(x2 - x3):
                ids = sorted([i+1, j+1, k+1])
                b.append(ids)

b.sort()
print(len(b))
for line in b:
    print(*line)
