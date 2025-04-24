from math import gcd
for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    e, f = a * d, b * d
    g, h = c * b, b * d
    i, j = e - g, f
    k, l = i // gcd(i, j), j // gcd(i, j)
    if abs(k) == 1:
        print(f'1/{l}')
    else: print('NOT NEIGHBORS')