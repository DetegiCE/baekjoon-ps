from itertools import accumulate as acc
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))[::-1]
    a = list(acc(a))[::-1]
    p = 0
    for i in range(n):
        p = max(p, a[i] * (i+1-k))
    print(p)