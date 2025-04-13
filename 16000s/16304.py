n, x = map(int, input().split())
a = sorted(list(map(int, input().split())))
b = 1
for i in range(1, n):
    if a[i-1] + a[i] > x: break
    b += 1
print(b)