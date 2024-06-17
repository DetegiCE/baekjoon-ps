n, k, s = map(int, input().split())
a = sorted(list(map(int, input().split())))[::-1]
for i in range(1, n):
    a[i] += a[i-1]
for i in range(n):
    if a[i] < k * s:
        continue
    print(i+1)
    break
