n = int(input())
a = 0
b = 0
for i in range(1, 100001):
    f = 0
    for j in range(i-1, -1, -1):
        d = i**2 - j**2
        if d == n:
            a = j
            b = i
            f = 1
            break
        elif d > n:
            break
    if f == 1:
        break
if b == 0:
    print('impossible')
else:
    print(a, b)