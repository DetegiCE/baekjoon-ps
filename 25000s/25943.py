n = int(input())
a = list(map(int, input().split()))
p = a[0] - a[1]
for i in range(2, n):
    if p == 0:
        p += a[i]
    elif p < 0:
        p += a[i]
    else:
        p -= a[i]
p = abs(p)
w = [100, 50, 20, 10, 5, 2, 1]
s = 0
for i in w:
    s += p // i
    p %= i
print(s)
