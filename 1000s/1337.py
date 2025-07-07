n = int(input())
a = sorted([int(input()) for _ in range(n)])
mx = 4
for i in range(1, 5):
    for j in range(n-i):
        if a[j+i] - a[j] <= 4:
            mx = min(mx, 4-i)
print(mx)