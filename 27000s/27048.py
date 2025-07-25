n, p, c = map(int, input().split())
a = [0 for _ in range(p)]
for i in range(n):
    x = int(input())
    a[x] += 1

l = 1
s = 0
ans = 0
for i in range(1, p):
    s += a[i]
    while s > c:
        s -= a[l]
        l += 1
    if i - l + 1 > ans:
        ans = i - l + 1
print(ans)

