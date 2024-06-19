from math import gcd
n = int(input())
a = list(map(int, input().split()))[::-1]
up = 1
dn = a[0]
for i in range(1, n):
    up += dn * a[i]
    up, dn = dn, up
    g = gcd(up, dn)
    up //= g
    dn //= g
print(dn-up, dn)
