from math import lcm
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = 1
    for i in a:
        b = lcm(b, i)
    if b > 1e9:
        print('More than a billion.')
    else:
        print(b)