n = int(input())
a = sorted(list(map(int, input().split())))
m = 1e18
for i in range(n):
    m = min(m, a[i] + a[n*2-i-1])
print(m)