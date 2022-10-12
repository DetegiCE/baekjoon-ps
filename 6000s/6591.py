from math import comb
while True:
    a, b = map(int, input().split())
    if a == b == 0:
        break
    print(comb(a, b))