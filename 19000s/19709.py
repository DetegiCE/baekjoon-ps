n, m = map(int, input().split())
k = [int(input()) for _ in range(m)]
k.sort()

c = 0
for i in range(m):
    if k[i] > n: break
    n -= k[i]
    c += 1
print(c)