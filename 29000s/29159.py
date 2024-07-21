from math import gcd
a, b = 0, 0
c, d = 0, 0
for i in range(4):
    p, q = map(int, input().split())
    a += p
    b += q
for i in range(4):
    p, q = map(int, input().split())
    c += p
    d += q
aaup = b-d
aadn = a-c
aag = gcd(aaup, aadn)
bbup = (aadn * b - aaup * a)
bbdn = aadn * 4
bbg = gcd(bbup, bbdn)

aaup //= aag
aadn //= aag
bbup //= bbg
bbdn //= bbg

if aaup * aadn > 0 and aaup < 0 or aaup * aadn < 0 and aaup > 0:
    aaup *= -1
    aadn *= -1
if bbup * bbdn > 0 and bbup < 0 or bbup * bbdn < 0 and bbup > 0:
    bbup *= -1
    bbdn *= -1

if aadn == 1:
    print(aaup, end=' ')
else:
    print(f'{aaup}/{aadn}', end=' ')
if bbdn == 1:
    print(bbup)
else:
    print(f'{bbup}/{bbdn}')