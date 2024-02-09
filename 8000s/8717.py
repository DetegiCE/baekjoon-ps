n = int(input())
a = list(map(int, input().split()))
s = sum(a)
t = 0
m = 1e18
for i in range(n-1):
    t += a[i]
    m = min(m, abs(s-t*2))
print(m)
