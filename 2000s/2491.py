n = int(input())
a = list(map(int, input().split()))
l = 1
m = 1
for i in range(1, n):
    if a[i-1] <= a[i]:
        l += 1
        m = max(m, l)
    else:
        l = 1
l = 1
for i in range(n-2, -1, -1):
    if a[i+1] <= a[i]:
        l += 1
        m = max(m, l)
    else:
        l = 1
print(m)