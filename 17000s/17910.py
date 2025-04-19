from math import gcd as g
n = int(input())
a = list(map(int, input().split()))
up, dn = 0, 1
for i in range(n-1, -1, -1):
    up += dn * a[i]
    gc = g(up, dn)
    up //= gc
    dn //= gc
    if not i: break
    up, dn = dn, up
print(up, dn, sep='/')