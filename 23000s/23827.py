n = int(input())
a = list(map(int, input().split()))
c = [a[0]]
for i in range(1, n):
    c.append(c[-1] + a[i])
s = 0
for i in range(n-1, 0, -1):
    s += a[i] * c[i-1]
    s %= 1000000007
print(s)
