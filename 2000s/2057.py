from math import factorial as fac
n = 0
flg = 0

fs = []
for i in range(21, -1, -1):
    fs.append(fac(i))
n = int(input())

if n == 0:
    print('NO')
    exit(0)

for i in fs:
    if n >= i:
        n -= i
if n == 0: print('YES')
else: print('NO')
